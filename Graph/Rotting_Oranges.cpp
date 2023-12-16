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

bool check(int i, int j, int n, int m, vvi& grid, vvi& v) {
    if (i < 0 || j < 0 || i == n || j == m || v[i][j] == 1 || grid[i][j] != 1) return false;
    return true;
}

int orangesRotting(vvi& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vvi v(n, vector<int>(m, 0));
    queue<pii> q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                v[i][j] = 1;
                q.push({i, j});
            }
            else if (grid[i][j] == 0) {
                v[i][j] = 1;
            }
        }
    }

    int ans = 0;

    while (!q.empty()) {
        queue<pair<int, int>> a;
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (check(i - 1, j, n, m, grid, v)) {
                a.push({i - 1, j});
                v[i - 1][j] = 1;
            }
            if (check(i + 1, j, n, m, grid, v)) {
                a.push({i + 1, j});
                v[i + 1][j] = 1;
            }
            if (check(i, j - 1, n, m, grid, v)) {
                a.push({i, j - 1});
                v[i][j - 1] = 1;
            }
            if (check(i, j + 1, n, m, grid, v)) {
                a.push({i, j + 1});
                v[i][j + 1] = 1;
            }
        }
        ans++;
        q = a;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0 && grid[i][j] == 1) return -1;
        }
    }

    return max(0, ans - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vvi v(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> v[i][j];
    }

    cout << orangesRotting(v) << endl;
    return 0;
}