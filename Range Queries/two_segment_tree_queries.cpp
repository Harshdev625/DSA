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

class Segment_Tree{
    public:
    vi seg;
    Segment_Tree(int n){
        seg.resize(4*n+1,0);
    }

    void build(int index,int low,int high,vi&v){
    if(low==high){
            seg[index]=v[low];
            return;
        }
        int mid=(low+high)/2;

        build(2*index+1,low,mid,v);
        build(2*index+2,mid+1,high,v);
        seg[index]=min(seg[2*index+1],seg[2*index+2]);
    }

    int query(int index,int low,int high,int left,int right){
        if(right<low || high<left)return INT_MAX;
        if(low>=left && high<=right)return seg[index];
        int mid= (low+high)>>1;
        int l=query(2*index+1,low,mid,left,right);
        int r=query(2*index+2,mid+1,high,left,right);
        return min(l,r);
    }

    void update(int index,int low,int high,int i,int val){
        if(low==high){
            seg[index]=val;
            return;
        }
        int mid=(low+high)>>1;
        if(i<=mid) update(2*index+1,low,mid,i,val);
        else update(2*index+2,mid+1,high,i,val);
        seg[index]=min(seg[2*index+1],seg[2*index+2]);
    }
};


int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int n1;
    cin>>n1;
    vi v1(n1);
    for(int i=0;i<n1;i++)cin>>v1[i];
    Segment_Tree st1(n1);
    st1.build(0,0,n1-1,v1);
    int n2;
    cin>>n2;
    vi v2(n2);
    for(int i=0;i<n2;i++)cin>>v2[i];
    Segment_Tree st2(n2);
    st2.build(0,0,n2-1,v2);
    int q;
    cin>>q;
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            int min1= st1.query(0,0,n1-1,l1,r1);
            int min2= st2.query(0,0,n2-1,l2,r2);
            cout<<min(min1,min2)<<nl;
        }
        else{
            int arrNo,index,val;
            cin>>arrNo>>index>>val;
            if(arrNo==1){
                st1.update(0,0,n1-1,index,val);
                v1[index]=val;
            }
            else{
                st2.update(0,0,n2-1,index,val);
                v2[index]=val;
            }
        }
    }
	return 0;
}