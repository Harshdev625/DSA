#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define vvvi vector<vector<vector<int>>>
#define vll vector<long long>
#define mii map<int, int>
#define umap unordered_map<int, int>
#define uset unordered_set<int>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sz size()
#define f first
#define s second
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9
#define min_pq priority_queue<ll, vector<ll>, greater<ll>>
#define init(a,n) for(ll i=0; i<n; i++) { cin>>a[i]; }
#define F0R(i, a) for (ll i=0; i<(a); i++)
#define print(a) for(const auto&i: (a)){cerr<<i<<" ";}cerr<<nl;

#define N 100005
ll power[N];
ll inverse[N];
ll stringhash[N];

ll add(ll a,ll b,ll mod){
    ll ans =(a+b)%mod;
    if(ans<0){
        ans+=mod;
    }
    return ans;
}

ll mul(ll a,ll b,ll mod){
    ll ans =(a*b)%mod;
    if(ans<0){
        ans+=mod;
    }
    return ans;
}

// Computed in O(log(b))
ll pow(ll a,ll b,ll mod){
    ll ans=1;
    while(b){
        if(b%2){
            ans= mul(ans,a,mod);
        }
        a= mul(a,a,mod);
        b/=2;
    }
    return ans;
}
// O(N)
void pre_cal(){
    power[0]=1;
    for(ll i=1;i<N;i++){
        power[i]=mul(power[i-1],31,MOD);
    }
    inverse[0]=1;
    for(ll i=1;i<N;i++){
        inverse[i]=pow(power[i],MOD-2,MOD);
    }
}
// O(N)
void build(string s){
    ll n=s.size();
    stringhash[0]=s[0];
    for(ll i=1;i<n;i++){
        stringhash[i]=add(stringhash[i-1],mul(s[i],power[i],MOD),MOD);
    }
}
// O(1)
ll gethash(ll a,ll b){
    ll ans= (a==0? stringhash[b]: add(stringhash[b],-stringhash[a-1],MOD));
    ans= mul(ans,(a==0? 1: inverse[a]),MOD);
    return ans;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}