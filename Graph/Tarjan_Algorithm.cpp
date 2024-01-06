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
int timer=1;

void dfs(vi&visited,vvi&graph,int n,vi&time,vi&low,int parent,vvi &bridges){
    visited[n]=1;
    time[n]=low[n]=timer;
    timer++;
    for(int i=0;i<graph[n].size();i++){
        if(graph[n][i]==parent)continue;
        if(!visited[graph[n][i]]){
            dfs(visited,graph,graph[n][i],time,low,n,bridges);
            low[n]=min(low[n],low[graph[n][i]]);
            if(low[graph[n][i]]>time[n]){
                bridges.pb({graph[n][i],n});
            }
        }
        else{
            low[n]=min(low[n],low[graph[n][i]]);
        }
    }
}

vvi criticalConnections(int n, vvi& edges) {
    vvi graph(n);
    for(auto&i:edges){
        int u=i[0];
        int v=i[1];
        graph[u].pb(v);
        graph[v].pb(u);
    }
    vvi bridges;
    vi visited(n,0);
    vi time(n);
    vi low(n);
    dfs(visited,graph,0,time,low,-1,bridges);
    return bridges;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v , e ;
    cin >> v >> e ;
    vvi edges;
    int a,b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b ;
        vi v;
        v.pb(a);
        v.pb(b);
        edges.pb(v);
    }
    vvi ans = criticalConnections(v,edges);
    for(const auto&i:ans){
        cout<<i[0]<<" "<<i[1]<<nl;
    }
    return 0;
}