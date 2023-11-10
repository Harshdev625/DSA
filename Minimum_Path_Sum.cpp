#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vll vector<long long>
#define mii map<int, int>
#define pb push_back
#define f second_last
#define s last
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9

int recursive_minimum_path_sum(int i,int j,vvi &v){
    // Time Complexity:O(2^(M+N))
    // Space Complexity:O(N)
    if(i<0 || j<0 )return INT_MAX;
    if(i==0 && j==0)return v[i][j];
    return v[i][j]+min(recursive_minimum_path_sum(i-1,j,v) , recursive_minimum_path_sum(i,j-1,v));
}

int memoization_minimum_path_sum(int i,int j,vvi&v,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    if(i<0 || j<0 )return INT_MAX;
    if(i==0 && j==0)dp[i][j]=v[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=v[i][j]+min(memoization_minimum_path_sum(i-1,j,v,dp),memoization_minimum_path_sum(i,j-1,v,dp));
}


int dynamic_programming_minimum_path_sum(int n,int m,vvi&v,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    dp=v;
    for (int i = 1; i < n; i++) dp[i][0] = v[i][0] + dp[i - 1][0];
    for (int j = 1; j < m; j++) dp[0][j] = v[0][j] + dp[0][j - 1];
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=v[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}

int space_optimization(int n,int m,vvi&v){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N)
    vi dp(m,0);
    dp[0]=v[0][0];
    for(int i=1;i<m;i++)dp[i]=dp[i-1]+v[0][i];
    for(int i=1;i<n;i++){
        vi t=dp;
        for(int j=0;j<m;j++){
            t[j]=v[i][j] + min(dp[j],(j>0?t[j-1]:INT_MAX));
        }
        dp=t;
    }
    return dp[m-1];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >>m;
    vvi v(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>v[i][j];
    }
    vvi dp(n, vi(m,-1));
    int result_recursive = recursive_minimum_path_sum(n-1,m-1,v);
    int result_memoization = memoization_minimum_path_sum(n-1,m-1,v,dp);
    int result_dynamic = dynamic_programming_minimum_path_sum(n,m,v,dp);
    int result_space_optimization = space_optimization(n,m,v);

    cout << "minimum_path_sum using Recursive: " << result_recursive << nl;
    cout << "minimum_path_sum using Memoization: " << result_memoization << nl;
    cout << "minimum_path_sum using Dynamic Programming: " << result_dynamic << nl;
    cout << "minimum_path_sum using Space Optimization: " << result_space_optimization << nl;

    return 0;
}