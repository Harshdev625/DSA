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

vector<int> recursive_Largest_Divisible_Subset(int i,int n,int j,vi &v,vi & a){
    // Time Complexity: O(2^n)
    // Space Complexity: O(N)
    if(i==n)return a;
    vi v1=recursive_Largest_Divisible_Subset(i+1,n,j,v,a),v2;
    if(j==-1 || v[i]%v[j]==0){
        vi t=a;
        t.push_back(v[i]);
        v2=recursive_Largest_Divisible_Subset(i+1,n,i,v,t);
    }
    return v1.size()>v2.size()? v1 : v2;
}

vector<int> hashing(int n,vi &v){
    // Time Complexity: O(N^2)
    // Space Complexity: O(N)
    vi dp(n,1);
    vi t;
    int lastindex=0,maxi=0;
    for(int i=0;i<n;i++)t.push_back(i);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]%v[j]==0 && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                t[i]=j;
                if(maxi < dp[i]){
					maxi = dp[i];
					lastindex=max(lastindex,i);
				}
            }
        }
    }
    vi ans;
    ans.push_back(v[lastindex]);
    while(lastindex!=t[lastindex]){
        lastindex= t[lastindex];
        ans.push_back(v[lastindex]);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n ;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vvi dp(n+1, vi(n+1,-1));
    sort(v.begin(),v.end());
    vi a;

    vector<int> result_recursive = recursive_Largest_Divisible_Subset(0,n,-1,v,a);
    vector<int> result_hashing = hashing(n,v);

    cout << "Largest_Divisible_Subset using Recursive: ";
    for(auto &i:result_recursive){
        cout<<i<<" ";
    }
    cout<<nl;
    cout << "Largest_Divisible_Subset using Hashing: ";
    for(auto &i:result_hashing){
        cout<<i<<" ";
    }
    cout<<nl;

    return 0;
}