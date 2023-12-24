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

vi dijkstra(vvi &edges, int v, int e, int start,int end){
    vector<vector<pair<int,int>>> graph(v+1);
    int n=edges.size();
    for(int i=0;i<n;i++){
        graph[edges[i][0]].pb({edges[i][1],edges[i][2]});
        graph[edges[i][1]].pb({edges[i][0],edges[i][2]});
    }
    vi distance(v+1,INT_MAX);
    vi parent(v+1,-1);
    distance[start]=0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        pair<int,int>p = pq.top();
        pq.pop();
        for(int i=0;i<graph[p.s].size();i++){
            if(distance[graph[p.s][i].f]>distance[p.s]+graph[p.s][i].s){
                distance[graph[p.s][i].f]=distance[p.s]+graph[p.s][i].s;
                pq.push({distance[graph[p.s][i].f],graph[p.s][i].f});
                parent[graph[p.s][i].f]=p.s;
            }
        }
    }
    vi ans;
    while(end!=-1){
        ans.pb(end);
        end=parent[end];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v, e, start , end;
    cin >> v >> e >> start >> end;
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

    vi ans =dijkstra(edges,v,e,start,end);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}