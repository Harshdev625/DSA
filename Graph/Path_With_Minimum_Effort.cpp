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

int minimumEffortPath(vector<vector<int>>& grid) {
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    int n=grid.size();
    int m=grid[0].size();
    vvi distance(n,vi(m,INF));
    pq.push({1,{0,0}});
    distance[0][0]=0;
    vi r={-1,1,0,0};
    vi c={0,0,-1,1};
    while(!pq.empty()){
        pair<int,pii>p=pq.top();
        pq.pop();
        for(int i=0;i<4;i++){
            int x=p.s.f+r[i];
            int y=p.s.s+c[i];
            if(x>=0 && x<n && y>=0 && y<m && max( distance[p.s.f][p.s.s],abs(grid[p.s.f][p.s.s]-grid[x][y]))< distance[x][y]){
                distance[x][y]=max( distance[p.s.f][p.s.s],abs(grid[p.s.f][p.s.s]-grid[x][y]));
                pq.push({distance[x][y],{x,y}});
            }
        }        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<distance[i][j]<<" ";
        }
        cout<<nl;
    }
    return distance[n-1][m-1]; 
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n,m;
    cin>>n>>m;
    vvi matrix(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>matrix[i][j];
    }
    int ans=minimumEffortPath(matrix);
    cout<<ans<<nl;
	return 0;
}
