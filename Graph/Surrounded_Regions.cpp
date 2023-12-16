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

void dfs(int i, int j, int n, int m, vector<vector<char>>& board, vvi& v) {
    if (i < 0 || j < 0 || i >= n || j >= m || v[i][j] == 1 || board[i][j] == 'X')return;
    v[i][j] = 1;
    dfs(i - 1, j, n, m, board, v);
    dfs(i + 1, j, n, m, board, v);
    dfs(i, j - 1, n, m, board, v);
    dfs(i, j + 1, n, m, board, v);
}

void solve(vector<vector<char>>& board) {
    int n = board.size();
    if (n == 0) return;
    int m = board[0].size();
    vvi v(n, vi(m, 0));

    for (int i = 0; i < n; i++) {
        if (board[i][0] == 'O' && v[i][0] == 0) {
            dfs(i, 0, n, m, board, v);
        }
        if (board[i][m - 1] == 'O' && v[i][m - 1] == 0) {
            dfs(i, m - 1, n, m, board, v);
        }
    }
    for (int j = 0; j < m; j++) {
        if (board[0][j] == 'O' && v[0][j] == 0) {
            dfs(0, j, n, m, board, v);
        }
        if (board[n - 1][j] == 'O' && v[n - 1][j] == 0) {
            dfs(n - 1, j, n, m, board, v);
        }
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (board[i][j] == 'O' && v[i][j] == 0) {
                board[i][j] = 'X';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<char>>v(n,vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> v[i][j];
    }
    
    solve(v);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}