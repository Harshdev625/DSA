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

bool compare(string a, string b) {
    int i = 0, j = 0, count = 0, n = a.size(), m = b.size();
    if ((abs(n - m)) != 1) return false;
    while (i < n && j < m) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            if (count == 1)
                return false;
            else {
                count++;
                n > m ? i++ : j++;
            }
        }
    }
    return true;
}

int longestStrChain(vector<string>& v) {
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
    sort(v.begin(), v.end(),[](const string& a, const string& b) { return a.size() > b.size(); });
    int n = v.size();
    vi dp(n, 1);
    vi t;
    int lastindex = 0, maxi = 0;

    for (int i = 0; i < n; i++) t.push_back(i);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (compare(v[i], v[j]) && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                t[i] = j;
                if (maxi < dp[i]) {
                    maxi = dp[i];
                    lastindex = max(lastindex, i);
                }
            }
        }
    }
    return max(maxi, 1);
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int result =longestStrChain(v);
    cout << "Longest_String_Chain : "<< result << nl;
    return 0;
}