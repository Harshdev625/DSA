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

vi shortestPath(int n, vvi&edges, int src) {
    vvi graph(n);
    for(int i=0;i<edges.size();i++){
        graph[edges[i][0]].pb(edges[i][1]);
        graph[edges[i][1]].pb(edges[i][0]);
    }
    vi distance(n,INF);
    distance[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        int t=q.front();
        for(int i=0;i<graph[t].size();i++){
            if(1+distance[t]<distance[graph[t][i]]){
                distance[graph[t][i]]=1+distance[t];
                q.push(graph[t][i]);
            }
        }
        q.pop();
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
    int a,b,src;
    for (int i = 0; i < e; i++) {
        cin>>a>>b;
        vi v;
        v.pb(a);
        v.pb(b);
        edges.pb(v);
    }
    cin>>src;
    vi ans =shortestPath(v,edges,src);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}