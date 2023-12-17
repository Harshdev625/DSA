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

void dfs(int i,int j,int&n,int&m,int x,int y,vvi&grid,vvi&v,vector<pii>&v1){
    if(i<0 ||j<0 ||i>=n ||j>=m ||grid[i][j]==0 ||v[i][j]==1)return;
    v[i][j]=1;
    grid[i][j]=0;
    v1.pb({i-x,j-y});
    dfs(i-1,j,n,m,x,y,grid,v,v1);
    dfs(i+1,j,n,m,x,y,grid,v,v1);
    dfs(i,j-1,n,m,x,y,grid,v,v1);
    dfs(i,j+1,n,m,x,y,grid,v,v1);
}

int numEnclaves(vvi& grid) {
    set<vector<pii>>s;
    int n = grid.size(), m = grid[0].size();
    vvi v(n, vi(m, 0));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1){
                vector<pii> v1;
                dfs(i,j,n,m,i,j,grid,v,v1);
                s.insert(v1);
            }
        }
    }
    return s.size();
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
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ans<<nl;
    return 0;
}