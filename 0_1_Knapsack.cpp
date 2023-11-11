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

int recursive_0_1_knapsack(int i,int w,vi &weight,vi &value){
    // Time Complexity:O(2^N)
    // Space Complexity:O(N)
    if(i==0){
        if(w-weight[0]>=0)return value[0];
        return 0;
    }
    int nottake=recursive_0_1_knapsack(i-1,w,weight,value);
    int take= (w-weight[i]>=0?value[i]+recursive_0_1_knapsack(i-1,w-weight[i],weight,value):0);
    return max(take,nottake);
}

int memoization_0_1_knapsack(int i,int w,vi &weight,vi &value,vvi &dp){
    // Time Complexity:O(N*k)
    // Space Complexity:O(N*k)
    if(i<0 || w<=0){
        return 0;
    }
    if(dp[i][w]!=-1)return dp[i][w];
    int nottake=memoization_0_1_knapsack(i-1,w,weight,value,dp);
    int take= (w-weight[i]>=0?value[i]+memoization_0_1_knapsack(i-1,w-weight[i],weight,value,dp):0);
    return dp[i][w]=max(take,nottake);
}

int dynamic_programming_0_1_knapsack(int n,int &w,vi &weight,vi &value,vvi &dp){
    // Time Complexity:O(N*k)
    // Space Complexity:O(N*k)
    for(int i=0;i<=w;i++){
        if(i-weight[0]>=0)dp[0][i]=value[0];
        else dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=w;j++){
            dp[i][j]= max(dp[i-1][j],(j-weight[i]>=0?dp[i-1][j-weight[i]]+value[i]:0));
        }
    }
    return dp[n][w];
}

int space_optimization(int n,int &w,vi &weight,vi &value){
    // Time Complexity:O(N*k)
    // Space Complexity:O(k)
    vi dp(w+1,0);
    for(int i=0;i<=w;i++){
        if(i-weight[0]>=0)dp[i]=value[0];
        else dp[i]=0;
    }
    for(int i=1;i<n;i++){
        vi t(w+1,0);
        for(int j=0;j<=w;j++){
            t[j]= max(dp[j],(j-weight[i]>=0?dp[j-weight[i]]+value[i]:0));
        }
        dp=t;
    }
    return dp[w];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n ;
    vi weight(n);
    for(int i=0;i<n;i++)cin>>weight[i];
    vi value(n);
    for(int i=0;i<n;i++)cin>>value[i];
    int w;
    cin>>w;
    vvi dp(n, vi(w+1,-1));

    int result_recursive = recursive_0_1_knapsack(n-1,w,weight,value);
    int result_memoization = memoization_0_1_knapsack(n-1,w,weight,value,dp);
    int result_dynamic = dynamic_programming_0_1_knapsack(n-1,w,weight,value,dp);
    int result_space_optimization = space_optimization(n,w,weight,value);

    cout << "0_1_knapsack using Recursive: " << result_recursive << endl;
    cout << "0_1_knapsack using Memoization: " << result_memoization << endl;
    cout << "0_1_knapsack using Dynamic Programming: " << result_dynamic << endl;
    cout << "0_1_knapsack using Space Optimization: " << result_space_optimization << endl;

    return 0;
}