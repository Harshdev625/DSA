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

int removeStones(vvi &stones){
    int n=stones.size();
    int row=0,col=0;
	for(auto&i:stones){
        row=max(row,i[0]);
        col=max(col,i[1]);
    }
    Disjoint_Set ds(row+col+1);
    unordered_map<int,int>m;
    for(auto&i:stones){
        ds.unionBySize(i[0],i[1]+row+1);
        m[i[0]]=1;
        m[i[1]+row+1]=1;
    }
    int count=0;
    for(auto&i:m){
        if(ds.find_parent(i.f)==i.f)count++;
    }
    return n-count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vvi stones;
    int a,b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b ;
        vi v;
        v.pb(a);
        v.pb(b);
        stones.pb(v);
    }
    int ans = removeStones(stones);
    cout<<ans;
    return 0;
}