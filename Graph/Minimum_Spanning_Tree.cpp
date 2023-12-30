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

int minimumSpanningTree(vector<vector<int>>& edges, int n){
    vector<vector<pii>>graph(n);
    int e=edges.size();
    for(int i=0;i<e;i++){
        graph[edges[i][0]].pb({edges[i][1],edges[i][2]});
        graph[edges[i][1]].pb({edges[i][0],edges[i][2]});
    }
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    vi visited(n,0);
    int sum=0;
    pq.push({0,0});
    while(!pq.empty()){
        int weight=pq.top().f;
        int node=pq.top().s;
        pq.pop();
        if(!visited[node]){
            sum+=weight;
            visited[node]=1;
            for(int i=0;i<graph[node].size();i++){
                if(!visited[graph[node][i].f]){
                    pq.push({graph[node][i].s,graph[node][i].f});
                }
            }
        }
        
    }
    return sum;
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
    int ans = minimumSpanningTree(edges,v);
    cout<<ans;
    return 0;
}