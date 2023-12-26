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

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vvi dp(n+1,vi(n+1,INF));
    for(int i=0;i<=n;i++)dp[i][i]=0;
    for(auto&it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        dp[u][v]=wt;
    }
    for(int s=0;s<=n;s++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(dp[i][s]!=INF && dp[s][j]!=INF)dp[i][j]=min(dp[i][j],dp[i][s]+dp[s][j]);
            }
        }
    }
    return dp[src][dest];
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int v , e ,src, end;
    cin >> v >> e >> src >>end;
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
    int ans = floydWarshall(v,e,src,end,edges);
    cout<<ans;
    return 0;
}