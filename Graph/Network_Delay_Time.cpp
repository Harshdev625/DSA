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

int networkDelayTime(vvi &edges, int v, int k){
    vector<vector<pii>> graph(v+1);
    int n=edges.size();
    for(int i=0;i<n;i++){
        graph[edges[i][0]].pb({edges[i][1],edges[i][2]});
    }
    vi distance(v+1,INF);
    queue<pii>q;
    q.push({0,k});
    distance[k]=0;
    while(!q.empty()){
        int node=q.front().s;
        int step=q.front().f;
        q.pop();
        for(int i=0;i<graph[node].size();i++){
            if(distance[graph[node][i].f]>graph[node][i].s+step){
                distance[graph[node][i].f]=graph[node][i].s+step;
                q.push({graph[node][i].s+step,graph[node][i].f});
            }
        }
    }
    // for(int i=0;i<n;i++)cout<<distance[i]<<" ";
    // cout<<nl;
    for(int i=1;i<=v;i++){
        if(distance[i]==INF)return -1;
    }
    return *max_element(distance.begin() + 1, distance.end());
}

int findCheapestPrice(int m, vector<vector<int>>& flights, int start, int end, int k) {
    int n=flights.size();
    vector<vector<pair<int,int>>> graph(m);
    for(int i=0;i<n;i++){
        graph[flights[i][0]].pb({flights[i][1],flights[i][2]});
    }
    // k++;
    vi cost(m,INF);
    queue<pair<int,pii>>q;
    cost[start]=0;
    q.push({0,{start,0}});
    while(!q.empty()){
        pii p=q.front().s;
        int step=q.front().f;
        q.pop();
        if(step>k)continue;
        for(int i=0;i<graph[p.f].size();i++){
            if( cost[graph[p.f][i].f]> p.s+graph[p.f][i].s){
                cost[graph[p.f][i].f]=p.s+graph[p.f][i].s;
                q.push({step + 1, {graph[p.f][i].f,cost[graph[p.f][i].f]}});
            }
        }
    }
    return cost[end]!=INF? cost[end] : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v , e , k;
    cin >> v >> e >> k;
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
    int ans = networkDelayTime(edges,v,k);
    cout<<ans<<nl;
    return 0;
}