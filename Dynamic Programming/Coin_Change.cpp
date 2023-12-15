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

int recursive_coin_change(int i,int total,vi &v){
    // Time Complexity:O(total^N)  
    // Space Complexity:O(N)
    if(i==0){
        if(total%v[i]==0)return total/v[i];
        return 1e9;
    }
    return min(((total-v[i]>=0) ? 1+recursive_coin_change(i,total-v[i],v) : 1000000000),recursive_coin_change(i-1,total,v));
}

int memoization_coin_change(int i,int total,vi &v,vvi &dp){
    // Time Complexity:O(N*total)
    // Space Complexity:O(N*total)
    if (i == 0){
        if(total % v[i] == 0) return dp[i][total] = total / v[i];
        return 1e9;
    }
    if(dp[i][total]!=-1)return dp[i][total];
    return dp[i][total]= min(((total-v[i]>=0) ? 1+memoization_coin_change(i,total-v[i],v,dp) : 1000000000),memoization_coin_change(i-1,total,v,dp));
}

int dynamic_programming_coin_change(int n,int& total,vi &v,vvi &dp){
    // Time Complexity:O(N*total)
    // Space Complexity:O(N*total)
    for(int i=0;i<=total;i++){
        if(i % v[0] == 0)dp[0][i]= i / v[0];
        else dp[0][i]=INF;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=total;j++){
            dp[i][j]= min(((j-v[i]>=0) ? 1+dp[i][j-v[i]] : 1000000000),dp[i-1][j]);
        }
    }
    return dp[n][total]>=INF?-1:dp[n][total];
}

int space_optimization(int n,int& total,vi &v){
    // Time Complexity:O(N*total)
    // Space Complexity:O(total)
    vi dp(total+1,1e9);
    vi t(total+1,1e9);
    for(int i=0;i<=total;i++){
        if(i % v[0] == 0)dp[i]= i / v[0];
        else dp[i]=INF;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=total;j++){
            t[j]= min(((j-v[i]>=0) ? 1+t[j-v[i]] : 1000000000),dp[j]);
        }
        dp = t;
    }
    return dp[total]>=INF? -1:dp[total];
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
    vvi  dp(n,vi(k+1,-1));

    int result_recursive = recursive_coin_change(n-1,k,v);
    if(result_recursive>=INF)result_recursive=-1;
    int result_memoization = memoization_coin_change(n-1,k,v,dp);
    if(result_memoization>=INF)result_memoization=-1;
    int result_dynamic = dynamic_programming_coin_change(n-1,k,v,dp);
    int result_space_optimization = space_optimization(n-1,k,v);

    cout << "coin_change using Recursive: " << result_recursive << endl;
    cout << "coin_change using Memoization: " << result_memoization << endl;
    cout << "coin_change using Dynamic Programming: " << result_dynamic << endl;
    cout << "coin_change using Space Optimization: " << result_space_optimization << endl;

    return 0;
}