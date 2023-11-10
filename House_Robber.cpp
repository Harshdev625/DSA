#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int> 
#define vll vector<long long>
#define mii map<int, int>
#define pb push_back
#define f second_last
#define s last
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9

int recursive_house_robber(int index,int & n,vi &v){
    // Time Complexity:O(2^N)
    // Space Complexity:O(N)
    if(index<0)return 0;
    int pick=v[index] + recursive_house_robber(index-2,n,v);
    int not_pick=recursive_house_robber(index-1,n,v);
    return max(pick,not_pick);
}

int memoization_house_robber(int index,vi &v,vi &dp){
    // Time Complexity:O(N)
    // Space Complexity:O(N)
    if(index<0)return 0;
    if (index == 0) dp[0]=v[0];
    if(dp[index]!=-1)return dp[index];
    int pick=v[index] + memoization_house_robber(index-2,v,dp);
    int not_pick=memoization_house_robber(index-1,v,dp);
    return dp[index]=max(pick,not_pick);
}

int dynamic_programming_house_robber(int n,vi &v,vi &dp){
    // Time Complexity:O(N)
    // Space Complexity:O(N)
    if(n>=0)dp[0]=v[0];
    if(n>=1)dp[1]=max(v[1],v[0]);
    for(int index=2;index<=n;index++){
        dp[index]=max({dp[index-1],dp[index-2]+v[index]});
    }
    return dp[n];
}

int space_optimization(int n,vi &v){
    // Time Complexity:O(N)
    // Space Complexity:O(1)
    vi dp(3,-1);
    if(n>=0)dp[0]=v[0];
    if(n>=1)dp[1]=max(v[1],v[0]);
    for(int index=2;index<=n;index++){
        dp[2]=max(v[index]+dp[0],dp[1]);
        dp[0]=dp[1];
        dp[1]=dp[2];
    }
    return n>=2?dp[2]:dp[n];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vi  dp(n+1, -1);

    int result_recursive = recursive_house_robber(n-1,n,v);
    int result_memoization = memoization_house_robber(n-1,v,dp);
    int result_dynamic = dynamic_programming_house_robber(n-1,v,dp);
    int result_space_optimization = space_optimization(n-1,v);

    cout << "house_robber using Recursive: " << result_recursive << nl;
    cout << "house_robber using Memoization: " << result_memoization << nl;
    cout << "house_robber using Dynamic Programming: " << result_dynamic << nl;
    cout << "house_robber using Space Optimization: " << result_space_optimization << nl;

    return 0;
}