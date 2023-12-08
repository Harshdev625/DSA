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

int Best_Time_to_Buy_and_Sell_Stock(vector<int> &v){
    int mini = v[0];
    int ans=0,n=v.size();
    for(int i=1;i<n;i++){
        ans=max(ans,v[i]-mini);
        mini=min(v[i],mini);
    }
    return ans;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        cout<<Best_Time_to_Buy_and_Sell_Stock(v)<<nl;
	}
	return 0;
}
