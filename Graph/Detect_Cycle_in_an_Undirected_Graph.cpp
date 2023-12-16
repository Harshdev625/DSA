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


bool dfs(int v,vi graph[],vi &visited,int parent){
    visited[v]=1;
    for(int i=0;i<graph[v].size();i++){
        if(!visited[graph[v][i]]){
            if (dfs(graph[v][i],graph,visited,v))return true;
        }
        else{
            if(graph[v][i]!=parent)return true;
        }
    }
    return false;
}

bool bfs(int v,vvi graph,vi visited){
    queue<pii>q;
    q.push({v,-1});

    while(!q.empty()){
        pii p=q.front();
        visited[p.f]=1;
        for(int i=0;i<graph[p.f].size();i++){
            if(!visited[graph[p.f][i]]){
                q.push({graph[p.f][i],p.f});
            }
            else{
                if(graph[p.f][i]!=p.s)return true;
            }
        }
        q.pop();
    }

    return false;
}

bool detectCycle(int v, vvi graph) {
    vi visited(v,0);
        for(int i=0;i<v;i++){
            if(!visited[i])if(bfs(i,graph,visited))return true;
        }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v, e;
    cin >> v >> e;
    vvi graph(v);
    int a,b;
    for (int i = 0; i < e; i++) {
        cin>>a>>b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    detectCycle(v,graph)? (cout<<"true") : (cout<<"false")<<nl;
    return 0;
}