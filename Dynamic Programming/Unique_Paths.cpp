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

int recursive_unique_paths(int i,int j){
    // Time Complexity:O(2^(M+N))
    // Space Complexity:O(N)
    if(i<0 || j<0)return 0;
    if(i==0 && j==0)return 1;
    return recursive_unique_paths(i-1,j) + recursive_unique_paths(i,j-1);
}

int memoization_unique_paths(int i,int j,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    if(i<0 || j<0)return 0;
    if(i==0 && j==0)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=memoization_unique_paths(i-1,j,dp)+memoization_unique_paths(i,j-1,dp);
}

int dynamic_programming_unique_paths(int n,int m,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    for(int i=0;i<n;i++)dp[i][0]=1;
    for(int j=0;j<m;j++)dp[0][j]=1;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return dp[n][m];
}

int space_optimization(int n,int m){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N)
    vi dp(m,1);
    for(int i=1;i<n;i++){
        vi t=dp;
        for(int j=1;j<m;j++){
            t[j]=dp[j]+t[j-1];
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
    vvi dp(n, vi(m,-1));
    int result_recursive = recursive_unique_paths(n-1,m-1);
    int result_memoization = memoization_unique_paths(n-1,m-1,dp);
    int result_dynamic = dynamic_programming_unique_paths(n-1,m-1,dp);
    int result_space_optimization = space_optimization(n,m);

    cout << "unique_paths using Recursive: " << result_recursive << nl;
    cout << "unique_paths using Memoization: " << result_memoization << nl;
    cout << "unique_paths using Dynamic Programming: " << result_dynamic << nl;
    cout << "unique_paths using Space Optimization: " << result_space_optimization << nl;

    return 0;
}