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

int recursive_Best_Time_to_Buy_and_Sell_Stock_II(bool buy,int taken ,int n,vi &v){
    // Time Complexity:O(2^N)
    // Space Complexity:O(N)
    if(n==-1)return -taken;
    if(buy){
        return max(taken-v[n]+recursive_Best_Time_to_Buy_and_Sell_Stock_II(true,v[n],n-1,v),max(taken-v[n]+recursive_Best_Time_to_Buy_and_Sell_Stock_II(false,0,n-1,v),recursive_Best_Time_to_Buy_and_Sell_Stock_II(buy,taken,n-1,v)));
    }
    return max(recursive_Best_Time_to_Buy_and_Sell_Stock_II(true,v[n],n-1,v),recursive_Best_Time_to_Buy_and_Sell_Stock_II(buy,taken,n-1,v));
}

int memoization_Best_Time_to_Buy_and_Sell_Stock_II(bool buy,int taken ,int n,vi &v,vvi &dp){
    // Time Complexity:O(N)
    // Space Complexity:O(N)
    if(n==-1)return -taken;
    if(dp[n][buy]!=-1)return dp[n][buy];
    if(buy){
        return dp[n][buy]=max(taken-v[n]+memoization_Best_Time_to_Buy_and_Sell_Stock_II(true,v[n],n-1,v,dp),max(taken-v[n]+memoization_Best_Time_to_Buy_and_Sell_Stock_II(false,0,n-1,v,dp),memoization_Best_Time_to_Buy_and_Sell_Stock_II(buy,taken,n-1,v,dp)));
    }
    return dp[n][buy]=max(memoization_Best_Time_to_Buy_and_Sell_Stock_II(true,v[n],n-1,v,dp),memoization_Best_Time_to_Buy_and_Sell_Stock_II(buy,taken,n-1,v,dp));
}

int dynamic_programming_Best_Time_to_Buy_and_Sell_Stock_II(int n,vi &v,vvi &dp){
    // Time Complexity:O(N)
    // Space Complexity:O(N)
    dp[n][0]=0;
    dp[n][1]=0;
    int profit;
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) {
                profit = max(0 + dp[i + 1][0], -v[i] + dp[i + 1][1]);
            }
            else{
                profit = max(0 + dp[i + 1][1], v[i] + dp[i + 1][0]);
            }
            dp[i][buy] = profit;
        }
    }
    return dp[0][0];
}

int space_optimization(int n,vi &v){
    // Time Complexity:O(N)
    // Space Complexity:O(1)
    vi dp(2,0);
    vi t(2,0);
    dp[0]=0;
    dp[1]=0;
    int profit;
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            if (buy == 0) {
                profit = max(0 + dp[0], -v[i] + dp[1]);
            }
            else{
                profit = max(0 + dp[1], v[i] + dp[0]);
            }
            t[buy] = profit;
        }
        dp=t;
    }
    return dp[0];
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
    vvi dp(n+1, vi(2,-1));

    int result_recursive = recursive_Best_Time_to_Buy_and_Sell_Stock_II(false,0,n-1,v);
    int result_memoization = memoization_Best_Time_to_Buy_and_Sell_Stock_II(false,0,n-1,v,dp);
    int result_dynamic = dynamic_programming_Best_Time_to_Buy_and_Sell_Stock_II(n,v,dp);
    int result_space_optimization = space_optimization(n,v);

    cout << "Best_Time_to_Buy_and_Sell_Stock_II using Recursive: " << result_recursive << endl;
    cout << "Best_Time_to_Buy_and_Sell_Stock_II using Memoization: " << result_memoization << endl;
    cout << "Best_Time_to_Buy_and_Sell_Stock_II using Dynamic Programming: " << result_dynamic << endl;
    cout << "Best_Time_to_Buy_and_Sell_Stock_II using Space Optimization: " << result_space_optimization << endl;

    return 0;
}