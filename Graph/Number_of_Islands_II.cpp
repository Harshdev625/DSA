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
    vi parent, rank, size;

   public:
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

bool valid(int x, int y, int n, int m) {
    if (x < 0 || y < 0 || x >= n || y >= m) return false;
    return true;
}

vector<int> numberOfIslandII(int n, int m, vvi& queries, int q) {
    Disjoint_Set ds(n * m);
    vvi visited(n, vi(m, 0));
    int count = 0;
    vector<int> ans(q);
    vi x = {-1, 0, 1, 0};
    vi y = {0, -1, 0, 1};
    
    for (int i = 0; i < q; i++) { 
        int r = queries[i][0]; 
        int c = queries[i][1];
        if (visited[r][c]) {
            ans[i] = count;
            continue;
        }
        visited[r][c] = 1;
        count++;
        for (int j = 0; j < 4; j++) {
            int adjx = r + x[j];
            int adjy = c + y[j];
            if (valid(adjx, adjy, n, m)) {
                if (visited[adjx][adjy] == 1) {
                    int node = r * m + c;
                    int adjnode = adjx * m + adjy;
                    if (ds.find_parent(node) != ds.find_parent(adjnode)) {
                        ds.unionByRank(node, adjnode);
                        count--;
                    }
                }
            }
        }
        ans[i] = count;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n , m , q;
    cin >> n >> m >> q ;
    vvi queries(q,vi(2,0));
    int a ,b;
    for(int i=0;i<q;i++){
        cin >> a >> b ;
        queries[i][0]=a;
        queries[i][1]=b;
    }
    vi ans = numberOfIslandII(n,m,queries,q);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}