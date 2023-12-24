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

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    int n=grid.size();
    int m=grid[0].size();
    vvi distance(n,vi(m,INF));
    if(grid[0][0]==0){
        pq.push({1,{0,0}});
        distance[0][0]=1;
    }
    while(!pq.empty()){
        pair<int,pii>p=pq.top();
        pq.pop();
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int x=p.s.f+i;
                int y=p.s.s+j;
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==0 && 1+distance[p.s.f][p.s.s]< distance[x][y]){
                    distance[x][y]=1+distance[p.s.f][p.s.s];
                    pq.push({distance[x][y],{x,y}});
                }
            }
        }
    }
    return distance[n-1][m-1]==INF?-1 : distance[n-1][m-1];
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
    int ans=shortestPathBinaryMatrix(matrix);
    cout<<ans<<nl;
	return 0;
}
