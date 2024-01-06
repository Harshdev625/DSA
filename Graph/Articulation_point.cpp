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
int timer=0;

void dfs(vi&visited,vvi&graph,int n,vi&time,vi&low,int parent,vi&mark){
    visited[n]=1;
    time[n]=low[n]=timer;
    timer++;
    int child=0;
    for(int i=0;i<graph[n].size();i++){
        if(graph[n][i]==parent)continue;
        if(!visited[graph[n][i]]){
            dfs(visited,graph,graph[n][i],time,low,n,mark);
            low[n]=min(low[n],low[graph[n][i]]);
            if(low[graph[n][i]]>=time[n] && parent!=-1){
                mark[n]=1;
            }
            child++;
        }
        else{
            low[n]=min(low[n],time[graph[n][i]]);
        }
    }
    if(child>1 && parent==-1){
        mark[n]=1;
    }
}

vi Articulation_point(int n, vvi& edges) {
    vvi graph(n+1);
    for(auto&i:edges){
        int u=i[0];
        int v=i[1];
        graph[u].pb(v);
        graph[v].pb(u);
    }
    vi visited(n+1,0);
    vi time(n+1);
    vi low(n+1);
    vi mark(n+1,0);
    vi ans;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(visited,graph,i,time,low,-1,mark);
        }
    }
    for(int i=1;i<=n;i++){
        if(mark[i])ans.pb(i);
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
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
        vi ans = Articulation_point(v,edges);
        for(const auto&i:ans){
            cout<<i<<" ";
        }
        cout<<nl;
    }
    
    return 0;
}