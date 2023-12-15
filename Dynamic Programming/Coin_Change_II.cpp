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
#define f first
#define s second
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9

int recursive_coin_change_ii(int i,int total,vi &v){
    // Time Complexity:O(total^N)  
    // Space Complexity:O(N)
    if(i==-1){
        if(total==0)return 1;
        return 0;
    }
    return ((total-v[i]>=0) ? recursive_coin_change_ii(i,total-v[i],v) : 0)+recursive_coin_change_ii(i-1,total,v);
}

int memoization_coin_change_ii(int i,int total,vi &v,vvi &dp){
    // Time Complexity:O(N*total)
    // Space Complexity:O(N*total)
    if (i == -1){
        if(total==0)return 1;
        return 0;
    }
    if(dp[i][total]!=-1)return dp[i][total];
    return dp[i][total]= ((total-v[i]>=0) ? memoization_coin_change_ii(i,total-v[i],v,dp) : 0 )+ memoization_coin_change_ii(i-1,total,v,dp);
}

int dynamic_programming_coin_change_ii(int n,int& total,vi &v,vvi &dp){
    // Time Complexity:O(N*total)
    // Space Complexity:O(N*total)
    for(int i=0;i<=total;i++){
        if(i % v[0] == 0)dp[0][i]= 1;
        else dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=total;j++){
            dp[i][j]= ((j-v[i]>=0) ? dp[i][j-v[i]] : 0)+dp[i-1][j];
        }
    }
    return dp[n][total];
}

int space_optimization(int n,int& total,vi &v){
    // Time Complexity:O(N*total)
    // Space Complexity:O(total)
    vi dp(total+1,0);
    vi t(total+1,0);
    for(int i=0;i<=total;i++){
        if(i % v[0] == 0)dp[i]= 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=total;j++){
            t[j]= ((j-v[i]>=0) ? t[j-v[i]] : 0)+dp[j];
        }
        dp = t;
    }
    return dp[total];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin >> n ;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    cin >> k;
    vvi  dp(n,vi(k+1,-1));

    int result_recursive = recursive_coin_change_ii(n-1,k,v);
    int result_memoization = memoization_coin_change_ii(n-1,k,v,dp);
    int result_dynamic = dynamic_programming_coin_change_ii(n-1,k,v,dp);
    int result_space_optimization = space_optimization(n-1,k,v);

    cout << "coin_change_ii using Recursive: " << result_recursive << endl;
    cout << "coin_change_ii using Memoization: " << result_memoization << endl;
    cout << "coin_change_ii using Dynamic Programming: " << result_dynamic << endl;
    cout << "coin_change_ii using Space Optimization: " << result_space_optimization << endl;

    return 0;
}