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

void add(int &n,int&x){
    n|= (1<<x);
}

void remove(int &n,int&x){
    if((1<<x) & n){
        n^= (1<<x);
    }
}

void display(int &n){
    for(int i=0;i<32;i++){
        if(n & (1<<i)){
            cout<<i<<nl;
        }
    }
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    display(n);
    int x;
    cin>>x;
    remove(n,x);
    display(n);
    cin>>x;
    add(n,x);
    display(n);
    return 0;
}