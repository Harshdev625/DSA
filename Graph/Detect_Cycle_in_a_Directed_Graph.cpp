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

bool dfs(vvi&graph,vi&visited,int i,vi&pathvis){
    visited[i]=1;
    pathvis[i]=1;
    for(int j=0;j<graph[i].size();j++){
        if(!visited[graph[i][j]]){
            if(dfs(graph,visited,graph[i][j],pathvis))return true;
        }
        else{
            if(pathvis[graph[i][j]])return true;
        }
    }
    pathvis[i]=0;
    return false;
}

bool isCyclic(vvi& edges, int v, int e){
	vvi graph(v);
    for(int i=0;i<e;i++){
        graph[edges[i][0]].pb(edges[i][1]);
    }
    vi visited(v,0);
    vi pathvis(v,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(dfs(graph,visited,i,pathvis))return true;
        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v, e;
    cin >> v >> e;
    vvi edges;
    int a,b;
    for (int i = 0; i < e; i++) {
        cin>>a>>b;
        vi v;
        v.pb(a);
        v.pb(b);
        edges.pb(v);
    }

    bool ans =isCyclic(edges,v,e);
    (ans ? (cout<<"true") : (cout<<"false"))<<nl;
    return 0;
}