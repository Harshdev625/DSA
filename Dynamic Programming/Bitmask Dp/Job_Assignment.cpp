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

ll memo(ll i,ll &n,ll &mask,vvll &v,vvll &dp){
    if(i==n){
        return 0;
    }
    if(dp[i][mask]!=-1)return dp[i][mask];
    ll ans=LLONG_MAX;
    for(ll j=0;j<n;j++){
        if((1LL<<j) & mask){
            // mask ^= (1LL<<j);  this will change mask and when backtrack cause wrong answer 
            ll new_mask = mask ^ (1LL << j);
            ans= min(ans, v[i][j]+ memo(i+1,n, new_mask,v,dp));
        }
    }
    return dp[i][mask]=ans;
}

void solve(){
    ll n;
    cin>>n;
    vvll v(n,vll(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    // for(int i=0;i<n;i++){
    //     print(v[i]);
    // }
    ll mask = (1LL<<n)-1;
    vvll dp(n,vll((1LL<<n),-1));
    cout<<memo(0,n,mask,v,dp)<<nl;
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