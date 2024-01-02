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

class Disjoint_Set {

   public:
    vi parent, rank, size;
    Disjoint_Set(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find_parent(int n) {
        if (n == parent[n]) return n;
        return parent[n] = find_parent(parent[n]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = find_parent(u);
        int ulp_v = find_parent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_v]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = find_parent(u);
        int ulp_v = find_parent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

bool check(int x,int y,int n){
    if(x<0 ||y<0 ||x>=n || y>=n)return false;
    return true;
}
int largestIsland(vector<vector<int>>& grid) {
    int n=grid.size();
    Disjoint_Set ds(n*n);
    vi x={-1,1,0,0};
    vi y={0,0,-1,1};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!grid[i][j])continue;
            for(int k=0;k<4;k++){
                int newr=x[k]+i;
                int newc=y[k]+j;
                if(check(newr,newc,n) && grid[newr][newc]){
                    ds.unionBySize(i*n+j,newr*n+newc);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j])continue;
            set<int>s;
            for(int k=0;k<4;k++){
                int newr=x[k]+i;
                int newc=y[k]+j;
                if(check(newr,newc,n) && grid[newr][newc]){
                    s.insert(ds.find_parent(newr*n+newc));
                }
            }
            int total=0;
            for(auto&i:s){
                total+=ds.size[i];
            }
            total++;
            ans=max(ans,total);
        }
    }
    for(int i=0;i<n*n;i++){
        ans=max(ans,ds.size[ds.find_parent(i)]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n ;
    cin >> n ;
    vvi matrix(n,vi(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)cin>>matrix[i][j];
    }
    int ans = largestIsland(matrix);
    cout<<ans;
    return 0;
}