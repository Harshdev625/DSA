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

int recursive_triangle(int i,int j,vvi &v,int n){
    // Time Complexity:O(2^(N*(N-1)/2))
    // Space Complexity:O(N*(N-1)/2)
    if (i == n)return v[i][j];

    // Recursive case: Move to the i below and consider two adjacent numbers.
    int leftPath = recursive_triangle( i + 1, j,v,n);
    int rightPath = recursive_triangle( i + 1, j + 1,v,n);

    // Calculate the minimum path sum from the current position.
    return v[i][j] + min(leftPath, rightPath);
}

int memoization_triangle(int i,int j,vvi&v,vvi &dp,int n){
    // Time Complexity:O(N*(N-1)/2)
    // Space Complexity:O(N*(N-1)/2)
    if (i == n)dp[i][j]= v[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=v[i][j]+min(memoization_triangle(i+1,j,v,dp,n),memoization_triangle(i+1,j+1,v,dp,n));
}


int dynamic_programming_triangle(int n,int m,vvi&v,vvi &dp){
    // Time Complexity:O(N*(N-1)/2)
    // Space Complexity:O(N*(N-1)/2)
    dp=v;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=i;j++){
            dp[i][j]=v[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}

int space_optimization(int n,int m,vvi&v){
    // Time Complexity:O(N*(N-1)/2)
    // Space Complexity:O(N*(N-1)/2)
    vi dp=v[n];
    for(int i=n-1;i>=0;i--){
        vi t=dp;
        t.pop_back();
        for(int j=0;j<=i;j++){
            t[j]=v[i][j] + min(dp[j],dp[j+1]);
        }
        dp.pop_back();
        dp=t;
    }
    return dp[0];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vvi v(n);
    for (int i = 0; i < n; i++) {
        v[i] = vi(i + 1, 0);
        for (int j = 0; j <= i; j++) cin >> v[i][j];
    }
    vvi dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = vi(i + 1, -1);
    }
    int result_recursive = recursive_triangle(0, 0, v,n-1);
    int result_memoization = memoization_triangle(0,0,v,dp,n-1);
    int result_dynamic = dynamic_programming_triangle(n-1,n-1,v,dp);
    int result_space_optimization = space_optimization(n-1,n-1,v);

    cout << "triangle using Recursive: " << result_recursive << nl;
    cout << "triangle using Memoization: " << result_memoization << nl;
    cout << "triangle using Dynamic Programming: " << result_dynamic << nl;
    cout << "triangle using Space Optimization: " << result_space_optimization << nl;

    return 0;
}