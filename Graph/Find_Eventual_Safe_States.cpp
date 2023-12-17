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

bool dfs(vvi&graph,vi&visited,int i,vi&pathvis,vi&check){
    visited[i]=1;
    pathvis[i]=1;
    check[i]=0;
    for(int j=0;j<graph[i].size();j++){
        if(!visited[graph[i][j]]){
            if(dfs(graph,visited,graph[i][j],pathvis,check))return true;
        }
        else{
            if(pathvis[graph[i][j]])return true;
        }
    }
    check[i]=1;
    pathvis[i]=0;
    return false;
}

vi eventualSafeNodes(vvi& edges,int v,int e) {
    vvi graph(v);
    vi ans;
    for(int i=0;i<e;i++){
        graph[edges[i][0]].pb(edges[i][1]);
    }
    vi visited(v,0);
    vi pathvis(v,0);
    vi check(v,0);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(graph,visited,i,pathvis,check);
        }
    }
    for(int i=0;i<v;i++){
        if(check[i])ans.pb(i);
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

    vi ans =eventualSafeNodes(edges,v,e);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}