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