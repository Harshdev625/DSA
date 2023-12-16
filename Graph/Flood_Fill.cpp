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

void dfs(vvi &image,vvi &v, int n, int m, int x, int y, int p,int &q){
    if(x<0 || y<0 || x>=n || y>=m || v[x][y]==1 || image[x][y]!=q)return;
    v[x][y]=1;
    image[x][y]=p;
    dfs(image,v,n,m,x-1,y,p,q);
    dfs(image,v,n,m,x+1,y,p,q);
    dfs(image,v,n,m,x,y-1,p,q);
    dfs(image,v,n,m,x,y+1,p,q);
}

vvi floodFill(vvi &image, int n, int m, int x, int y, int p) {
    vvi v(n,vi(m,0));
    int t=image[x][y];
    dfs(image,v,n,m,x,y,p,t);
    return image;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int r,c,p;
    cin >> r >> c >> p;
    vvi v(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> v[i][j];
    }
    floodFill(v,n,m,r,c,p);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}