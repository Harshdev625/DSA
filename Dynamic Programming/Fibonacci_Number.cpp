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

int recursive_fibonacci(int n){
    // Time Complexity:O(2^N)
    // Space Complexity:O(N)
    if(n==0)return 0;
    else if(n==1)return 1;
    return recursive_fibonacci(n-1)+recursive_fibonacci(n-2);
}

int memoization_fibonacci(int n,vector<int>&dp){
    // Time Complexity:O(N)
    // Space Complexity:O(N)
    if (n == 0) dp[0]=0;
    if (n <= 1) dp[1]=1;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=memoization_fibonacci(n - 1, dp) + memoization_fibonacci(n - 2, dp);
}

int dynamic_programming_fibonacci(int n,vector<int>&dp){
    // Time Complexity:O(N)
    // Space Complexity:O(N)
    if(n>=0)dp[0]=0;
    if(n>=1)dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int space_optimization(int n){
    // Time Complexity:O(N)
    // Space Complexity:O(1)
    if(n==0)return 0;
    if(n==1)return 1;
    int second_last=0;
    int last=1;
    int ans;
    for(int i=2;i<=n;i++){
        ans=second_last+last;
        second_last=last;
        last=ans;
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
    vector<int> dp(n+1, -1);

    int result_recursive = recursive_fibonacci(n);
    int result_memoization = memoization_fibonacci(n, dp);
    int result_dynamic = dynamic_programming_fibonacci(n, dp);
    int result_space_optimization = space_optimization(n);

    cout << "Fibonacci using Recursive: " << result_recursive << endl;
    cout << "Fibonacci using Memoization: " << result_memoization << endl;
    cout << "Fibonacci using Dynamic Programming: " << result_dynamic << endl;
    cout << "Fibonacci using Space Optimization: " << result_space_optimization << endl;

    return 0;
}