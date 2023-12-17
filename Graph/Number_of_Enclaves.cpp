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

void dfs(int i,int j,int&n,int&m,vvi&grid,vvi&v){
    if(i<0 ||j<0 ||i>=n ||j>=m ||grid[i][j]==0 ||v[i][j]==1)return;
    v[i][j]=1;
    grid[i][j]=0;
    dfs(i-1,j,n,m,grid,v);
    dfs(i+1,j,n,m,grid,v);
    dfs(i,j-1,n,m,grid,v);
    dfs(i,j+1,n,m,grid,v);
}

int numEnclaves(vvi& grid) {
    int n = grid.size(), m = grid[0].size();
    vvi v(n, vi(m, 0));
    for (int i = 0; i < n; i++) {
        if (v[i][0] == 0 && grid[i][0] == 1) {
            dfs(i, 0, n, m, grid, v);
        }
        if (v[i][m - 1] == 0 && grid[i][m - 1] == 1) {
            dfs(i, m - 1, n, m, grid, v);
        }
    }
    for (int i = 0; i < m; i++) {
        if (v[0][i] == 0 && grid[0][i] == 1) {
            dfs(0, i, n, m, grid, v);
        }
        if (v[n - 1][i] == 0 && grid[n - 1][i] == 1) {
            dfs(n - 1, i, n, m, grid, v);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) ans++;
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

    vvi v(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> v[i][j];
    }

    int ans =numEnclaves(v);
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans<<nl;
    return 0;
}