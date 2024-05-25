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
#define print(a) for(const auto&i: (a)){cout<<i<<" ";}

set <ll> factors(ll n){
    set<ll>s;
    s.insert(1);
    s.insert(n);
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    return s;
}

vector<ll> primes(){
    vector<ll>primes;
    vector<bool>is_prime(100001, true);
    is_prime[0]=is_prime[1]=false;
    for(ll i=2; i*i<=100000; i++){
        if(is_prime[i]){
            for(ll j=i*i; j<=100000; j+=i){
                is_prime[j]=false;
            }
        }
    }
    for(ll i=2; i<=100000; i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
    return primes;
}

class ST{
    vector<ll>seg,lazy;
    public:
    ST(ll n){
        seg.resize(4*n+1,0);
        lazy.resize(4*n+1,0);
    }
    void build(ll index,ll l,ll h,vll &v){
        if(l==h){
            seg[index]=v[l];
            return;
        }
        ll mid = l + (h-l)/2;
        build(2*index+1,l,mid,v);
        build(2*index+2,mid+1,h,v);
        seg[index]= seg[2*index+1]+ seg[2*index+2];
    }
    void update(ll index,ll low ,ll high,ll l,ll r,ll val){
        if(lazy[index]!=0){
            seg[index]+=(high-low+1)*lazy[index];
            if(low!=high){
                lazy[2*index+1]+=lazy[index];
                lazy[2*index+2]+=lazy[index];
            }
            lazy[index]=0;
        }
        if(l>high || r<low)return;
        if(low>= l && high<=r){
            seg[index]+=(high-low+1)*val;
            if(low!=high){
                lazy[2*index+1]+=val;
                lazy[2*index+2]+=val;
            }
            return;
        }
        ll mid = low + (high-low)/2;
        update(2*index+1,low,mid,l,r,val);
        update(2*index+2,mid+1,high,l,r,val);
        seg[index]= seg[2*index+1]+ seg[2*index+2];
    }
    ll query(ll index,ll low,ll high,ll l,ll r){
        if(lazy[index]!=0){
            seg[index]+=(high-low+1)*lazy[index];
            if(low!=high){
                lazy[2*index+1]+=lazy[index];
                lazy[2*index+2]+=lazy[index];
            }
            lazy[index]=0;
        }
        if(l>high || r<low)return 0;
        if(low>=l && high<=r)return seg[index];
        ll mid = low + (high-low)/2;
        ll left = query(2*index+1,low,mid,l,r);
        ll right = query(2*index+2,mid+1,high,l,r);
        return left+right;
    }
};

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n,q;
    cin>>n>>q;
    vll v(n);
    init(v,n);

    ST seg(n);
    seg.build(0,0,n-1,v);

    for(ll i=0;i<q;i++){
        ll type;
        cin>>type;
        if(type==2){
            ll l;
            cin>>l;
            cout << seg.query(0, 0, n - 1, l - 1, l - 1) << nl;
        }
        else{
            ll l,r,val;
            cin>>l>>r>>val;
            seg.update(0,0,n-1,l-1,r-1,val);
        }
    }

    return 0;
}