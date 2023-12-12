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

int longestBitonicSubsequence(vector<int>& v, int n)
{
	// Time Complexity: O(n^2)
    // Space Complexity: O(n)
	vi dp1(n,1);	
	vi dp2(n,1);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]>v[j] && dp1[i]<dp1[j]+1){
                dp1[i]=dp1[j]+1;
            }
        }
    }
	int ans=0;
	for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(v[i]>v[j] && dp2[i]<dp2[j]+1){
                dp2[i]=dp2[j]+1;
            }

        }
		ans=max(ans,dp1[i]+dp2[i]-1);
    }

    return ans;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int result =longestBitonicSubsequence(v,n);
    cout << "Longest_Bitonic_Subsequence : "<< result << nl;
    return 0;
}