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

int recursive_Best_Time_to_Buy_and_Sell_Stock_III(int day,int trade,int n,vi &v){
    // Time Complexity: O(2^(2k) * n)
    // Space Complexity: O(n)
    if(day==n || trade==0)return 0;
    bool buy = (trade%2==0);
    int ans1 = recursive_Best_Time_to_Buy_and_Sell_Stock_III( day + 1,trade,n,v),ans2=0;
    if(buy){
        ans2= -v[day]+recursive_Best_Time_to_Buy_and_Sell_Stock_III(day+1,trade-1,n,v);
    }
    else{
        ans2=v[day]+recursive_Best_Time_to_Buy_and_Sell_Stock_III(day+1,trade-1,n,v);
    }
    return max(ans1,ans2);
}

int memoization_Best_Time_to_Buy_and_Sell_Stock_III(int day,int trade,int n,vi &v,vvi &dp){
    // Time Complexity: O(2k * n)
    // Space Complexity: O(2k * n)
    if(day==n || trade==0)return 0;
    if(dp[day][trade]!=-1)return dp[day][trade];
    bool buy = (trade%2==0);
    int ans1 = memoization_Best_Time_to_Buy_and_Sell_Stock_III( day + 1,trade,n,v,dp),ans2=0;
    if(buy){
        ans2= -v[day]+memoization_Best_Time_to_Buy_and_Sell_Stock_III(day+1,trade-1,n,v,dp);
    }
    else{
        ans2=v[day]+memoization_Best_Time_to_Buy_and_Sell_Stock_III(day+1,trade-1,n,v,dp);
    }
    return max(ans1,ans2);
}

int dynamic_programming_Best_Time_to_Buy_and_Sell_Stock_III(int trade,int n,vi &v,vvi &dp){
    // Time Complexity: O(2k * n)
    // Space Complexity: O(2k * n)
    for(int i=0;i<=n;i++)dp[i][0]=0;
    for(int i=0;i<=trade;i++)dp[n][i]=0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= trade; j++) {
            bool buy = (j%2==0);
            int ans1=dp[i+1][j],ans2=0;
            if (buy) {
                ans2=-v[i]+dp[i+1][j-1];
            }
            else{
                ans2=v[i]+dp[i+1][j-1];
            }
            dp[i][j] = max(ans1,ans2);
        }
    }
    return dp[0][4];
}

int space_optimization(int trade,int n,vi &v){
    // Time Complexity: O(2k * n)
    // Space Complexity: O(2k)
    vi dp(5,0);
    vi t(5,0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 1; j <= trade; j++) {
            bool buy = (j%2==0);
            int ans1=dp[j],ans2=0;
            if (buy) {
                ans2=-v[i]+dp[j-1];
            }
            else{
                ans2=v[i]+dp[j-1];
            }
            t[j] = max(ans1,ans2);
        }
        dp=t;
    }
    return dp[4];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin >> n >>k;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int trade=2*k;
    vvi dp(n+1, vi(trade+1,-1));
    int result_recursive = recursive_Best_Time_to_Buy_and_Sell_Stock_III(0,trade,n,v);
    int result_memoization = memoization_Best_Time_to_Buy_and_Sell_Stock_III(0,trade,n,v,dp);
    int result_dynamic = dynamic_programming_Best_Time_to_Buy_and_Sell_Stock_III(trade,n,v,dp);
    int result_space_optimization = space_optimization(trade,n,v);

    cout << "Best_Time_to_Buy_and_Sell_Stock_III using Recursive: " << result_recursive << endl;
    cout << "Best_Time_to_Buy_and_Sell_Stock_III using Memoization: " << result_memoization << endl;
    cout << "Best_Time_to_Buy_and_Sell_Stock_III using Dynamic Programming: " << result_dynamic << endl;
    cout << "Best_Time_to_Buy_and_Sell_Stock_III using Space Optimization: " << result_space_optimization << endl;

    return 0;
}