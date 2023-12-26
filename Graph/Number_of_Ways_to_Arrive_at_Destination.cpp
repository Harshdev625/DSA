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
#define INF 1e18


int countPaths(int v, vector<vector<int>>& roads) {
    vector<vector<pll>> graph(v);
    int n = roads.size();
    for (int i = 0; i < n; i++) {
        graph[roads[i][0]].pb({roads[i][1], roads[i][2]});
        graph[roads[i][1]].pb({roads[i][0], roads[i][2]});
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> distance(v, INF);
    vector<ll> ways(v, 0);
    distance[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});
    while (!pq.empty()) {
        pll p = pq.top();
        pq.pop();
        for (int i = 0; i < graph[p.s].size(); i++) {
            if (distance[graph[p.s][i].f] > p.f + graph[p.s][i].s) {
                distance[graph[p.s][i].f] = p.f + graph[p.s][i].s;
                ways[graph[p.s][i].f] = ways[p.s];
                pq.push({distance[graph[p.s][i].f], graph[p.s][i].f});
            } else if (distance[graph[p.s][i].f] == p.f + graph[p.s][i].s) {
                ways[graph[p.s][i].f] =(ways[p.s] + ways[graph[p.s][i].f]) % MOD;
            }
        }
    }
    return ways[v - 1] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v , e ;
    cin >> v >> e ;
    vvi edges;
    int a,b,c;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        vi v;
        v.pb(a);
        v.pb(b);
        v.pb(c);
        edges.pb(v);
    }
    int ans = countPaths(v,edges);
    cout<<ans<<nl;
    return 0;
}