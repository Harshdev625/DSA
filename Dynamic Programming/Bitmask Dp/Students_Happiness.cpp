#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vvvi vector<vector<vector<ll>>>
#define mll map<ll, ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sz size()
#define f first
#define s second
#define nl endl
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9
#define min_pq priority_queue<ll, vector<ll>, greater<ll>>
#define init(a,n) for(ll i=0; i<n; i++) { cin>>a[i]; }
#define print(a) for(const auto&i: (a)){cerr<<i<<" ";}cerr<<nl;

ll memo(ll i,ll &n,ll&m,ll &mask,vvll &v ,vvll&dp){
    if(i==m){
        return 0;
    }
    if(dp[mask][i]!=-1)return dp[mask][i];
    ll ans=memo(i+1,n,m,mask,v,dp);
    for(ll j =0;j<n;j++){
        if((1LL<<j) &  mask){
            ll new_mask = mask ^(1LL<<j);
            ans= max(ans,v[i][j]+ memo(i+1,n,m,new_mask,v,dp));
        }
    }
    return dp[mask][i]= ans;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vvll v(m,vll(n));
    for(ll i=0;i<m;i++){
        for(ll j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    // for(int i=0;i<m;i++){
    //     print(v[i]);
    // }
    ll mask= (1LL<<n)-1;
    vvll dp((1LL<<n),vll(m,-1));
    cout<< memo(0,n,m,mask,v,dp)<<nl;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}