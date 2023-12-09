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

int recursive_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown(int buy,int day,int n,vi &v){
    // Time Complexity:O(2^N)
    // Space Complexity:O(N)
    if(day>=n)return 0;
    int ans1=recursive_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown(buy,day+1,n,v),ans2=0;
    if(buy==0){
        ans2=-v[day]+recursive_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown(buy+1,day+1,n,v);
    }
    else {
        ans2=v[day]+recursive_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown(buy-1,day+2,n,v);
    }
    return max(ans1,ans2);
}

int memoization_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown(int buy,int day,int n,vi &v,vvi &dp){
    // Time Complexity:O(N)
    // Space Complexity:O(N)
    if(day>=n)return 0;
    if(dp[day][buy]!=-1)return dp[day][buy];
    int ans1=memoization_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown(buy,day+1,n,v,dp),ans2=0;
    if(buy==0){
        ans2=-v[day]+memoization_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown(buy+1,day+1,n,v,dp);
    }
    else {
        ans2=v[day]+memoization_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown(buy-1,day+2,n,v,dp);
    }
    return dp[day][buy]=max(ans1,ans2);
}

int dynamic_programming_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown(int n,vi &v,vvi &dp){
    // Time Complexity:O(N)
    // Space Complexity:O(N)
    dp[n][0]=0;
    dp[n][1]=0;
    dp[n+1][0]=0;
    dp[n+1][1]=0;
    for (int i = n-1; i >=0; i--) {
        for (int j = 0; j <= 1; j++) {
            int ans1=dp[i+1][j],ans2=0;
            if (j == 0) {
                ans2 = -v[i]+dp[i+1][j+1];
            }
            else{
                ans2 = v[i]+dp[i+2][j-1];
            }
            dp[i][j] = max(ans1,ans2);
        }
    }
    return dp[0][0];
}

int space_optimization(int n,vi &v){
    // Time Complexity:O(N)
    // Space Complexity:O(1)
    vi dp(2,0);
    vi t1(2,0);
    vi t2(2,0);
    for (int i = n-1; i >=0; i--) {
        for (int j = 0; j <= 1; j++) {
            int ans1=t1[j],ans2=0;
            if (j == 0) {
                ans2 = -v[i]+t1[j+1];
            }
            else{
                ans2 = v[i]+t2[j-1];
            }
            dp[j] = max(ans1,ans2);
        }
        t2=t1;
        t1=dp;
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
    vvi dp(n+2, vi(2,-1));

    int result_recursive = recursive_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown(0,0,n,v);
    int result_memoization = memoization_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown(0,0,n,v,dp);
    int result_dynamic = dynamic_programming_Best_Time_to_Buy_and_Sell_Stock_with_Cooldown(n,v,dp);
    int result_space_optimization = space_optimization(n,v);

    cout << "Best_Time_to_Buy_and_Sell_Stock_with_Cooldown using Recursive: " << result_recursive << endl;
    cout << "Best_Time_to_Buy_and_Sell_Stock_with_Cooldown using Memoization: " << result_memoization << endl;
    cout << "Best_Time_to_Buy_and_Sell_Stock_with_Cooldown using Dynamic Programming: " << result_dynamic << endl;
    cout << "Best_Time_to_Buy_and_Sell_Stock_with_Cooldown using Space Optimization: " << result_space_optimization << endl;

    return 0;
}  