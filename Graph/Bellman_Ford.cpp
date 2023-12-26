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

vi bellmonFord(int n, int m,vvi &edges,int src) {
    vi distance(n,1e8);
    distance[src]=0;
    for(int i=0;i<n-1;i++){
        for(auto&it:edges){
            int u= it[0];
            int v= it[1];
            int weight=it[2];
            if(distance[u]!=1e8 && distance[u]+weight<distance[v]){
                distance[v]=distance[u]+weight;
            }
        }
    }
    for(auto&it:edges){
        int u= it[0];
        int v= it[1];
        int weight=it[2];
        if(distance[u]!=1e8 && distance[u]+weight<distance[v]){
            return {-1};
        }
    }
    return distance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v , e ,src;
    cin >> v >> e >> src;
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
    vi ans = bellmonFord(v,e,edges,src);
    for(auto&i:ans)cout<<i<<" ";
    return 0;
}