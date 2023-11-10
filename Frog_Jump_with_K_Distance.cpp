// Problem 
// https://atcoder.jp/contests/dp/tasks/dp_b
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

int recursive_frog_jump_with_k_distance(int index,int & k,int & n,vi &v){
    // Time Complexity:O(k^N)
    // Space Complexity:O(N)
    if(index==0)return 0;
    int jump=INT_MAX;
    int temp=INT_MAX;
    for(int i=1;i<=k;i++){
        if(index-i>=0)temp= abs(v[index]-v[index-i])+ recursive_frog_jump_with_k_distance(index-i,k,n,v);
        jump=min(temp,jump);
    }
    return jump;
}

int memoization_frog_jump_with_k_distance(int index,int &k,vi &v,vi &dp){
    // Time Complexity:O(N*k)
    // Space Complexity:O(N)
    if (index == 0) dp[0]=0;
    if(dp[index]!=-1)return dp[index];
    int jump=INT_MAX;
    int temp=INT_MAX;
    for(int i=1;i<=k;i++){
        if(index-i>=0)temp= abs(v[index]-v[index-i])+ memoization_frog_jump_with_k_distance(index-i,k,v,dp);
        jump=min(temp,jump);
    }
    return dp[index]=jump;
}

int dynamic_programming_frog_jump_with_k_distance(int n,int& k,vi &v,vi &dp){
    // Time Complexity:O(N*k)
    // Space Complexity:O(N)
    if(n>=0)dp[0]=0;
    if(n>=1)dp[1]=abs(v[1]-v[0]);
    for(int index=2;index<=n;index++){
        int temp=INT_MAX;
        for(int i=1;i<=k;i++){
            if(index-i>=0)temp= abs(v[index]-v[index-i])+ dp[index-i];
            dp[i]=min(temp,dp[i]);
        }
    }
    return dp[n];
}
int space_optimization(int n,int& k,vi &v){
    // Time Complexity:O(N)
    // Space Complexity:O(k)
    vi dp(n+1,INT_MAX);
    if(n>=0)dp[0]=0;
    if(n>=1)dp[1]=abs(v[1]-v[0]);
    for(int index=2;index<=n;index++){
        int temp=INT_MAX;
        for(int i=1;i<=k;i++){
            if(index-i>=0)temp= abs(v[index]-v[index-i])+ dp[index-i];
            dp[index] = min(temp, dp[index]);
        }
    }
    return dp[n];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vi  dp(n+1, -1);

    int result_recursive = recursive_frog_jump_with_k_distance(n-1,k,n,v);
    int result_memoization = memoization_frog_jump_with_k_distance(n-1,k,v,dp);
    int result_dynamic = dynamic_programming_frog_jump_with_k_distance(n-1,k,v,dp);
    int result_space_optimization = space_optimization(n-1,k,v);

    cout << "frog_jump_with_k_distance using Recursive: " << result_recursive << endl;
    cout << "frog_jump_with_k_distance using Memoization: " << result_memoization << endl;
    cout << "frog_jump_with_k_distance using Dynamic Programming: " << result_dynamic << endl;
    cout << "frog_jump_with_k_distance using Space Optimization: " << result_space_optimization << endl;

    return 0;
}