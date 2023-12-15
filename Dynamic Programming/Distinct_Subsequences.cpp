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

int recursive_distinct_subsequences(string a,string b,int i,int j){
    // Time Complexity:O(2^(max(n, m)))
    // Space Complexity:O(N)
    if(j<0)return 1;
    if(i<0)return 0;
    if(a[i]==b[j]){
        return recursive_distinct_subsequences(a,b,i-1,j-1) + recursive_distinct_subsequences(a,b,i-1,j);
    }
    return recursive_distinct_subsequences(a,b,i-1,j);
}

int memoization_distinct_subsequences(string a,string b,int m,int n,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    if(n<0)return 1;
    if(m<0)return 0;
    if(dp[m][n]!=-1)return dp[m][n];
    if(a[m]==b[n]){
        return dp[m][n]= memoization_distinct_subsequences(a,b,m-1,n-1,dp) + memoization_distinct_subsequences(a,b,m-1,n,dp);
    }
    return dp[m][n]= memoization_distinct_subsequences(a,b,m-1,n,dp);
}

int dynamic_programming_distinct_subsequences(string a,string b,int m,int n,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] % 1000000007;
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[m][n];
}

int space_optimization(string a,string b, int m,int n) {
    // Time Complexity: O(N*M)
    // Space Complexity: O(M)
    vi dp(n+1, 0);
    vi t(n+1,0);
    dp[0]=1;
    for (int i = 1; i <= m; i++) {
        t[0]=1;
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                t[j] = (dp[j - 1] + dp[j])% 1000000007;
            } else {
                t[j] = dp[j];
            }
        }
        dp=t;
    }
    return dp[n];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a,b;
    cin >> a >> b;
    int m= a.size();
    int n= b.size();
    vvi dp(m+1, vi(n+1,-1));
    int result_recursive = recursive_distinct_subsequences(a,b,m-1,n-1);
    int result_memoization = memoization_distinct_subsequences(a,b,m-1,n-1,dp);
    int result_dynamic = dynamic_programming_distinct_subsequences(a,b,m,n,dp);
    int result_space_optimization = space_optimization(a,b,m,n);

    cout << "distinct_subsequences using Recursive: " << result_recursive << endl;
    cout << "distinct_subsequences using Memoization: " << result_memoization << endl;
    cout << "distinct_subsequences using Dynamic Programming: " << result_dynamic << endl;
    cout << "distinct_subsequences using Space Optimization: " << result_space_optimization << endl;

    return 0;
}