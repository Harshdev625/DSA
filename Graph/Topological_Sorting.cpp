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

void dfs(vvi&graph,vi&visited,int i,stack<int>&s){
    visited[i]=1;
    for(int j=0;j<graph[i].size();j++){
        if(!visited[graph[i][j]]){
            dfs(graph,visited,graph[i][j],s);
        }
    }
    s.push(i);
}

vi topologicalSort(vvi &edges, int v, int e) {
    vvi graph(v);
    vi ans;
    stack<int>s;
    vi visited(v,0);
    for(int i=0;i<e;i++){
        graph[edges[i][0]].pb(edges[i][1]);
    }
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(graph,visited,i,s);
        }
    }
    while(!s.empty()){
        ans.pb(s.top());
        s.pop();
    }
    return ans;
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

    vi ans =topologicalSort(edges,v,e);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}