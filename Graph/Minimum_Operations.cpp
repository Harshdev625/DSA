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

int minimumOperations(int n, int start, int end, vi &v){
    vi distance(100000,INF);
    queue<pii>q;
    q.push({0,start});
    distance[start]=0;

    while(!q.empty()){
        pii p=q.front();
        q.pop();
        if(p.s==end)break;
        for(int i=0;i<n;i++){
            if(distance[(v[i]*p.s)%1000]>1+p.f){
                distance[(v[i]*p.s)%1000]=1+p.f;
                q.push({1+p.f,(v[i]*p.s)%1000});
            }
        }
    }
    return distance[end]==INF?-1 : distance[end];
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
    int n , start , end;
    cin >> n >> start >> end ;
    vi v(n);
    int a,b,c;
    for (int i = 0; i < n; i++)cin>>v[i];
    int ans = minimumOperations(n,start,end,v);
    cout<<ans<<nl;
    return 0;
}