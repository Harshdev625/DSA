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

int recursive_climbing_stairs(int n){
    // Time Complexity:O(2^N)
    // Space Complexity:O(N)
    if(n==0)return 1;
    if(n==1)return 1;
    return (recursive_climbing_stairs(n-1)% MOD)+(recursive_climbing_stairs(n-2)% MOD);
}

int memoization_climbing_stairs(int n,vector<int>&dp){
    // Time Complexity:O(N)
    // Space Complexity:O(N)
    if (n == 0) dp[0]=1;
    if (n <= 1) dp[1]=1;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=(memoization_climbing_stairs(n - 1, dp)% MOD) + (memoization_climbing_stairs(n - 2, dp)% MOD);
}

int dynamic_programming_climbing_stairs(int n,vector<int>&dp){
    // Time Complexity:O(N)
    // Space Complexity:O(N)
    if(n>=0)dp[0]=1;
    if(n>=1)dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-1]% MOD)+(dp[i-2]% MOD);
    }
    return dp[n]% MOD;
}
int space_optimization(int n){
    // Time Complexity:O(N)
    // Space Complexity:O(1)
    if(n==0)return 1;
    if(n==1)return 1;
    int second_last=1;
    int last=1;
    int ans;
    for(int i=2;i<=n;i++){
        ans=(second_last+last)%1000000007;
        second_last=last%1000000007;
        last=ans%1000000007;
    }
    return ans%1000000007;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);

    int result_recursive = recursive_climbing_stairs(n);
    int result_memoization = memoization_climbing_stairs(n, dp);
    int result_dynamic = dynamic_programming_climbing_stairs(n, dp);
    int result_space_optimization = space_optimization(n);

    cout << "climbing_stairs using Recursive: " << result_recursive << endl;
    cout << "climbing_stairs using Memoization: " << result_memoization << endl;
    cout << "climbing_stairs using Dynamic Programming: " << result_dynamic << endl;
    cout << "climbing_stairs using Space Optimization: " << result_space_optimization << endl;

    return 0;
}