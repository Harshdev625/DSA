#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vll vector<long long>
#define mii map<int, int>
#define pb push_back
#define f second_last
#define s last
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9

int recursive_target_sum(int i,int total,vi &v){
    // Time Complexity:O(total^N)  
    // Space Complexity:O(N)
    if(i==0){
        if(total-v[i]==0 || total+v[i]==0)return (total-v[i]==0) + (total+v[i]==0);
        return 0;
    }
    return recursive_target_sum(i-1,total-v[i],v)+recursive_target_sum(i-1,total+v[i],v);
}

int memoization_target_sum(int i,int k,vi &v,vvi &dp){
    // Time Complexity:O(N*total)
    // Space Complexity:O(N*total)
    if(k<0) return 0;
    if(i==0){
        if(v[i]==0 && k==0)return 2;
        if(v[i]==k || k==0)return 1;
        return 0;
    }
    if(i==0) return v[0]==k;
    if(dp[i][k]!=-1)return dp[i][k];
    return dp[i][k]=(memoization_target_sum(i-1,k-v[i],v,dp)%MOD+memoization_target_sum(i-1,k,v,dp)%MOD)%MOD;
}

int dynamic_programming_target_sum(int n,int& k,vi &v,vvi &dp){
    // Time Complexity:O(N*total)
    // Space Complexity:O(N*total)
    for(int i=0;i<=k;i++)dp[0][i]=0;
    dp[0][0]=1;
    if(v[0]<=k)dp[0][v[0]]+=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=(dp[i-1][j]%MOD+(j-v[i]>=0?dp[i-1][j-v[i]]:0)%MOD)%MOD;
        }
    }
    return dp[n][k];
}

int space_optimization(int n,int& k,vi &v){
    // Time Complexity:O(N*total)
    // Space Complexity:O(total)
    vi dp(k+1,0);
    vi t(k+1,0);
    dp[0]=1;
    if(v[0]<=k)dp[v[0]]+=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            t[j]=(dp[j]%MOD+(j-v[i]>=0?dp[j-v[i]]:0)%MOD)%MOD;
        }
        dp=t;
    }
    return dp[k];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int total=accumulate(v.begin(),v.end(),0);
    int calculate = (total-k)/2;
    vvi dp(n,vi(total>=k?calculate+1:k+1,-1));
    int result_recursive = (total>=k && (total-k)%2==0)?recursive_target_sum(n-1,k,v):0;
    int result_memoization = (total>=k && (total-k)%2==0)?memoization_target_sum(n-1,calculate,v,dp):0;
    int result_dynamic = (total>=k && (total-k)%2==0)?dynamic_programming_target_sum(n-1,calculate,v,dp):0;
    int result_space_optimization = (total>=k && (total-k)%2==0)?space_optimization(n-1,calculate,v):0;

    cout << "target_sum using Recursive: " << result_recursive << endl;
    cout << "target_sum using Memoization: " << result_memoization << endl;
    cout << "target_sum using Dynamic Programming: " << result_dynamic << endl;
    cout << "target_sum using Space Optimization: " << result_space_optimization << endl;

    return 0;
}