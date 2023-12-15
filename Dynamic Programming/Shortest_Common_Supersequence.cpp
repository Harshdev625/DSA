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

string recursive_shortest_common_supersequence_helper(string a, string b, int n, int m) {
    // Time Complexity: O(2^(max(n, m)))
    // Space Complexity: O(max(n, m))
    if (n < 0) return b.substr(0, m + 1);
    if (m < 0) return a.substr(0, n + 1);

    string s1, s2, s3;
    if (a[n] == b[m]) {
        s1 = recursive_shortest_common_supersequence_helper(a, b, n - 1, m - 1) + a[n];
    } else {
        s2 = recursive_shortest_common_supersequence_helper(a, b, n - 1, m) + a[n];
        s3 = recursive_shortest_common_supersequence_helper(a, b, n, m - 1) + b[m];
    }

    int a1 = s1.size(), b1 = s2.size(), c1 = s3.size();
    return (a1 <= b1 && a1 <= c1) ? s1 : (b1 <= a1 && b1 <= c1) ? s2 : s3;
}

string recursive_shortest_common_supersequence(string a, string b, int n, int m) {
    string match = recursive_shortest_common_supersequence_helper(a, b, n, m);
    reverse(match.begin(), match.end());
    string ans;
    int i = 0, j = 0, k = 0;
    while (i < n || j < m) {
        if (i < n && j < m && match[k] == a[i] && match[k] == b[j]) {
            ans.push_back(a[i]);
            i++;
            j++;
            k++;
        } else {
            if (i < n && (j == m || a[i] != match[k])) {
                ans.push_back(a[i]);
                i++;
            } else {
                ans.push_back(b[j]);
                j++;
            }
        }
    }
    return ans;
}

int memoization_shortest_common_supersequence_helper(string a, string b, int n, int m, vvi &dp) {
    // Time Complexity: O(N*M)
    // Space Complexity: O(N*M)
    if (n <= 0 || m <= 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];

    int nottake = max(memoization_shortest_common_supersequence_helper(a, b, n, m - 1, dp),
                      memoization_shortest_common_supersequence_helper(a, b, n - 1, m, dp));
    int take = (a[n - 1] == b[m - 1] ? 1 + memoization_shortest_common_supersequence_helper(a, b, n - 1, m - 1, dp) : 0);

    return dp[n][m] = max(take, nottake);
}

string memoization_shortest_common_supersequence(string a, string b, int n, int m, vvi &dp) {
    int a1 = memoization_shortest_common_supersequence_helper(a, b, n, m, dp);
    string match;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            match.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(match.begin(), match.end());
    string ans;
    int k = 0;
    for (int i = 0, j = 0; i < n || j < m;) {
        if (i < n && j < m && match[k] == a[i] && match[k] == b[j]) {
            ans.push_back(a[i]);
            i++;
            j++;
            k++;
        } else {
            if (i < n && (j == m || a[i] != match[k])) {
                ans.push_back(a[i]);
                i++;
            } else {
                ans.push_back(b[j]);
                j++;
            }
        }
    }
    return ans;
}

string dynamic_programming_shortest_common_supersequence(string a, string b, int n, int m, vvi &dp) {
    // Time Complexity: O(N*M)
    // Space Complexity: O(N*M)
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), (a[i - 1] == b[j - 1] ? 1 + dp[i - 1][j - 1] : 0));
        }
    }
    string match;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            match.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(match.begin(), match.end());
    string ans;
    int k = 0;
    for (int i = 0, j = 0; i < n || j < m;) {
        if (i < n && j < m && match[k] == a[i] && match[k] == b[j]) {
            ans.push_back(a[i]);
            i++;
            j++;
            k++;
        } else {
            if (i < n && a[i] != match[k]) {
                ans.push_back(a[i]);
                i++;
            } else {
                ans.push_back(b[j]);
                j++;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    vvi dp(n + 1, vi(m + 1, -1));

    string result_recursive = recursive_shortest_common_supersequence(a, b, n - 1, m - 1);
    string result_memoization = memoization_shortest_common_supersequence(a, b, n, m, dp);
    string result_dynamic = dynamic_programming_shortest_common_supersequence(a, b, n, m, dp);

    cout << "shortest_common_supersequence using Recursive: " << result_recursive << nl;
    cout << "shortest_common_supersequence using Memoization: " << result_memoization << nl;
    cout << "shortest_common_supersequence using Dynamic Programming: " << result_dynamic << nl;

    return 0;
}
