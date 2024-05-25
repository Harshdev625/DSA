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

void build(int index,int low,int high,vi&v,vi&seg){
    if(low==high){
        seg[index]=v[low];
        return;
    }
    int mid=(low+high)/2;

    build(2*index+1,low,mid,v,seg);
    build(2*index+2,mid+1,high,v,seg);
    seg[index]=min(seg[2*index+1],seg[2*index+2]);
}

int query(int index,int low,int high,int left,int right,vi&seg){
    if(right<low || high<left)return INT_MAX;
    if(low>=left && high<=right)return seg[index];
    int mid= (low+high)>>1;
    int l=query(2*index+1,low,mid,left,right,seg);
    int r=query(2*index+2,mid+1,high,left,right,seg);
    return min(l,r);
}

void update(int index,int low,int high,int i,int val,vi&seg){
    if(low==high){
        seg[index]=val;
        return;
    }
    int mid=(low+high)>>1;
    if(i<=mid) update(2*index+1,low,mid,i,val,seg);
    else update(2*index+2,mid,high,i,val,seg);
    seg[index]=min(seg[2*index+1],seg[2*index+2]);
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n;
    cin>>n;
    vi v(n);
    vi seg(4*n,0);
    for(int i=0;i<n;i++)cin>>v[i];
    build(0,0,n-1,v,seg);
    // for(auto&i:seg)cout<<i<<" ";
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(0,0,n-1,l,r,seg)<<nl;
    }
	return 0;
}
