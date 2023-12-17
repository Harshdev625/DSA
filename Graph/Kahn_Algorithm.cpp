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

vi Kahn_Algorithm(vvi &edges, int v, int e) {
    vvi graph(v);
    for(int i=0;i<e;i++){
        graph[edges[i][0]].pb(edges[i][1]);
    }
    vi ans;
    vi indegree(v,0);
    queue<int>q;
    vi visited(v,0);
    for(int i=0;i<e;i++){
        indegree[edges[i][1]]++;
    }
    for(int i=0;i<v;i++){
        if(!indegree[i]){
           q.push(i);
        }
    }
    while(!q.empty()){
        int t=q.front();
        for(int i=0;i<graph[t].size();i++){
            indegree[graph[t][i]]--;
            if(!indegree[graph[t][i]]){
                q.push(graph[t][i]);
            }
        }
        ans.pb(t);
        q.pop();
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

    vi ans =Kahn_Algorithm(edges,v,e);
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
    return 0;
}