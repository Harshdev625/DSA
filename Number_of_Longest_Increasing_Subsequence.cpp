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

int findNumberOfLIS(vector<int> &v)
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
    int n=v.size(),ans=0,maxi=1;
    vi dp(n,1);	
    vi count(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(v[i]>v[j] && dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                count[i]=count[j];
            }
            else if(v[i]>v[j] && dp[i]==dp[j]+1){
                count[i]+=count[j];
            }
        }
        maxi=max(maxi,dp[i]);
    }
    for(int i=0;i<n;i++){
        if(dp[i]==maxi){
            ans+=count[i];
        }
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

    int result =findNumberOfLIS(v);
    cout << "Number_of_Longest_Increasing_Subsequence : "<< result << nl;
    return 0;
}