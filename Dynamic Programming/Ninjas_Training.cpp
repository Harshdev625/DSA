#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vll vector<long long>
#define mii map<int, int>
#define pb push_back
#define f second_last
#define s last
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9

int recursive_ninjas_training(int index,int select,vvi &v){
    // Time Complexity:O(3^N)
    // Space Complexity:O(N)
    if(index<0)return 0;
    int total=INT_MIN;
    for(int i=0;i<3;i++){
        int temp=INT_MIN;
        if(select !=i)temp= v[index][i]+recursive_ninjas_training(index-1,i,v);
        total=max(temp,total);
    }
    return total;
}

int memoization_ninjas_training(int index,int select,vvi &v,vvi &dp){
    // Time Complexity:O(N^2)
    // Space Complexity:O(N^2)
    if(index<0)return 0;
    if(dp[index][select]!=0)return dp[index][select];
    int total=INT_MIN;
    for (int i = 0; i < 3; i++) {
        if (i != select) {
            int temp = v[index][i] + memoization_ninjas_training(index - 1, i, v, dp);
            total = max(temp, total);
        }
    }
    return dp[index][select]=total;
}

int dynamic_programming_ninjas_training(int n,vvi &v,vvi &dp){
    // Time Complexity:O(N^2)
    // Space Complexity:O(N^2)
    for (int i = 0; i < 3; i++) {
        dp[0][i] = v[0][i];
    }
    for(int index=1;index<=n;index++){
        for(int i=0;i<3;i++){
            int temp=INT_MIN;
            for(int j=0;j<3;j++){
                if(i!=j){
                    temp=max(dp[index-1][j],temp);
                }
            }
            dp[index][i]=v[index][i]+temp;
        }
    }
    return max({dp[n][0],dp[n][1],dp[n][2]});
}

int space_optimization(int n,vvi &v){
    // Time Complexity:O(N^2)
    // Space Complexity:O(N)
    vi dp(3,-1);
    for (int i = 0; i < 3; i++) {
        dp[i] = v[0][i];
    }
    for(int index=1;index<=n;index++){
        vector<int>t=dp;
        for(int i=0;i<3;i++){
            int temp=INT_MIN;
            for(int j=0;j<3;j++){
                if(i!=j){
                    temp=max(dp[j],temp);
                }
            }
            t[i]=v[index][i]+temp;
        }
        for (int i = 0; i < 3; i++) {
            dp[i] = t[i];
        }
        for(int i=0;i<3;i++)cout<<dp[i]<<nl;
    }
    return max({dp[0],dp[1],dp[2]});
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vvi v(n,vi(3));
    for(int i=0;i<n;i++){
        for(int j=0;j<=2;j++)cin>>v[i][j];
    }
    vvi dp(n, vi(4,0));
    int result_recursive = recursive_ninjas_training(n-1,-1,v);
    int result_memoization = memoization_ninjas_training(n-1,3,v,dp);
    int result_dynamic = dynamic_programming_ninjas_training(n-1,v,dp);
    int result_space_optimization = space_optimization(n-1,v);

    cout << "ninjas_training using Recursive: " << result_recursive << nl;
    cout << "ninjas_training using Memoization: " << result_memoization << nl;
    cout << "ninjas_training using Dynamic Programming: " << result_dynamic << nl;
    cout << "ninjas_training using Space Optimization: " << result_space_optimization << nl;

    return 0;
}