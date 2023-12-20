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

void dfs(int n,vector<vector<pair<int,int>>>&graph,stack<int>&s,vi &visited){
    visited[n]=1;
    for(int i=0;i<graph[n].size();i++){
        if(!visited[graph[n][i].f])dfs(graph[n][i].f,graph,s,visited);
    }
    s.push(n);
}
vi shortestPathInDAG(int n, int m, vector<vector<int>> &edges){
    vector<vector<pair<int,int>>>graph(n);
    for(int i=0;i<m;i++){
        graph[edges[i][0]].pb({edges[i][1],edges[i][2]});
    }
    vi visited(n,0);
    stack<int>s;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,graph,s,visited);
        }
    }
    vi distance(n,INF);
    distance[0]=0;
    while(!s.empty()){
        int t=s.top();
        s.pop();
        for(int i=0;i<graph[t].size();i++){
            if(distance[t]+graph[t][i].s<distance[graph[t][i].f]){
                distance[graph[t][i].f]=distance[t]+graph[t][i].s;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(distance[i]==INF)distance[i]=-1;
    }
    return distance;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v, e;
    cin >> v >> e;
    vvi edges;
    int a,b,c;
    for (int i = 0; i < e; i++) {
        cin>>a>>b>>c;
        vi v;
        v.pb(a);
        v.pb(b);
        v.pb(c);
        edges.pb(v);
    }

    vi ans =shortestPathInDAG(v,e,edges);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}