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

void dfs(vi&visited,vvi&graph,int n,stack<int>&s){
    visited[n]=1;
    for(int i=0;i<graph[n].size();i++){
        if(!visited[graph[n][i]])dfs(visited,graph,graph[n][i],s);
    }
    s.push(n);
}

int stronglyConnectedComponents(int n, vector<vector<int>> &edges){
	vvi graph(n);
    vvi reversegraph(n);
    for(auto&i:edges){
        int u=i[0];
        int v=i[1];
        graph[u].pb(v);
        reversegraph[v].pb(u);
    }
    stack<int>s;
    vi visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(visited,graph,i,s);
        }
    }
    int count=0;
    vi reversevisited(n,0);
    stack<int>s1;
    while(!s.empty()){
        int t=s.top();
        s.pop();
        if(!reversevisited[t]){
            count++;
            dfs(reversevisited,reversegraph,t,s1);
        }
    }
    return count;
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
    int ans = stronglyConnectedComponents(v,edges);
    cout<<ans;
    return 0;
}