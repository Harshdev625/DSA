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
unordered_map<string, int> m;
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    Disjoint_Set ds(n);
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < accounts[i].size(); j++) {
            if (m.count(accounts[i][j]) == 0) {
                m[accounts[i][j]] = i;
            } else {
                ds.unionByRank(i, m[accounts[i][j]]);
            }
        }
    }
    unordered_map<int, vector<string>> o;
    for (const auto& i : m) {
        o[ds.find_parent(i.s)].pb(i.f);
    }
    vector<vector<string>> ans;
    for (const auto& i : o) {
        vector<string> email = i.s;
        sort(email.begin(), email.end());
        vector<string> v;
        v.pb(accounts[i.f][0]);
        for (auto& j : email) {
            v.pb(j);
        }
        ans.pb(v);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n;
    vector<vector<string>> accounts;
    for (int i = 0; i < n; i++) {
        cin >> m;
        string s;
        vector<string>v;
        for(int j=0;j<m;j++){
            cin>>s;
            v.pb(s);
        }
        accounts.pb(v);
    }
    vector<vector<string>> ans = accountsMerge(accounts);
    for(const auto&i:ans){
        for(const auto&j:i)cout<<j<<" ";
        cout<<nl;
    }
    return 0;
}