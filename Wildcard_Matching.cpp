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

bool recursive_Wildcard_Matching(string a, string b, int m, int n) {
    // Time Complexity: O(2^(max(n, m)))
    // Space Complexity: O(max(n, m))
    if (n < 0) return m < 0;
    if (m < 0) {
        for (int i = 0; i <= n; ++i) {
            if (b[i] != '*') return false;
        }
        return true;
    }
    if (b[n] == '?' || a[m] == b[n])return recursive_Wildcard_Matching(a, b, m - 1, n - 1);
    else if (b[n] == '*')return recursive_Wildcard_Matching(a, b, m - 1, n) || recursive_Wildcard_Matching(a, b, m, n - 1);
    return false;
}

bool memoization_Wildcard_Matching(string a, string b, int m, int n, vvi &dp) {
    // Time Complexity: O(N * M)
    // Space Complexity: O(N * M)
    if (n < 0) return m < 0;
    if (m < 0) {
        for (int i = 0; i <= n; ++i) {
            if (b[i] != '*') return false;
        }
        return true;
    }
    if (dp[m][n] != -1) return dp[m][n];
    if (b[n] == '?' || a[m] == b[n])return dp[m][n]=memoization_Wildcard_Matching(a, b, m - 1, n - 1,dp);
    else if (b[n] == '*')return dp[m][n]=memoization_Wildcard_Matching(a, b, m - 1, n,dp) || memoization_Wildcard_Matching(a, b, m, n - 1,dp);
    return dp[m][n]=false;
}

bool dynamic_programming_Wildcard_Matching(string a, string b, int m, int n,vvi &dp) {
    // Time Complexity: O(N * M)
    // Space Complexity: O(N * M)
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    dp[0][0]=1;
    for (int j = 1; j <= n; j++) {
        if (b[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        } else {
            dp[0][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (b[j-1] == '?' || a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if( b[j-1]=='*'){
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
            else {
                dp[i][j] =0;
            }
        }
    }
    return dp[m][n];
}

int space_optimization(string a, string b, int m, int n) {
    // Time Complexity: O(N * M)
    // Space Complexity: O(max(N, M))
    vi dp(n + 1, 0);
    dp[0]=1;
    for (int j = 1; j <= n; j++) {
        if (b[j - 1] == '*') {
            dp[j] = dp[j - 1];
        } else {
            dp[j] = 0;
        }
    }
    vi t(n + 1, 0);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (b[j-1] == '?' || a[i - 1] == b[j - 1]) {
                t[j] = dp[j - 1];
            }
            else if( b[j-1]=='*'){
                t[j] = t[j-1] || dp[j];
            }
            else {
                t[j] =0;
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
    string a, b;
    cin >> a >> b;
    int m = a.size();
    int n = b.size();
    vvi dp(m + 1, vi(n + 1, -1));
    bool result_recursive = recursive_Wildcard_Matching(a, b, m - 1, n - 1);
    int result_memoization = memoization_Wildcard_Matching(a, b, m - 1, n - 1, dp);
    int result_dynamic = dynamic_programming_Wildcard_Matching(a, b, m, n, dp);
    int result_space_optimization = space_optimization(a, b, m, n);

    cout << "Wildcard_Matching using Recursive: " << (result_recursive?"true":"false") << endl;
    cout << "Wildcard_Matching using Memoization: " << (result_memoization?"true":"false") << endl;
    cout << "Wildcard_Matching using Dynamic Programming: " << (result_dynamic?"true":"false") << endl;
    cout << "Wildcard_Matching using Space Optimization: " << (result_space_optimization?"true":"false") << endl;

    return 0;
}