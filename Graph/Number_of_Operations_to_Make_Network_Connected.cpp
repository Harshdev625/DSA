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

int makeGraphConnected(int n, vector<pii> edges, int m) {
    Disjoint_Set ds(n);
    int count = 0;
    for (auto& i : edges) {
        int u = i.f;
        int v = i.s;
        if (ds.find_parent(u) != ds.find_parent(v)) {
            ds.unionByRank(u, v);
            count++;
        }
    }
    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(ds.find_parent(i));
    }
    return s.size() - 1 <= m - count ? s.size() - 1 : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v , e ;
    cin >> v >> e ;
    vector<pii> edges(e);
    int a,b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b ;
        edges[i]={a,b};
    }
    int ans = makeGraphConnected(v,edges,e);
    cout<<ans;
    return 0;
}