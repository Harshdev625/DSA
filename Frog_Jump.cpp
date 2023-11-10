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

int recursive_frog_jump(int i,int & n,vector<int>&v){
    // Time Complexity:O(2^N)
    // Space Complexity:O(N)
    if(i==0)return 0;
    int jump_1=INT_MAX;
    int jump_2=INT_MAX;
    if(i-1>=0)jump_1= abs(v[i]-v[i-1])+ recursive_frog_jump(i-1,n,v);
    if(i-2>=0)jump_2= abs(v[i]-v[i-2])+ recursive_frog_jump(i-2,n,v);
    return min(jump_1,jump_2);
}

int memoization_frog_jump(int i,vector<int>&v,vector<int>&dp){
    // Time Complexity:O(N)
    // Space Complexity:O(N)
    if (i == 0) dp[0]=0;
    if(dp[i]!=-1)return dp[i];
    int jump_1=INT_MAX;
    int jump_2=INT_MAX;
    if(i-1>=0)jump_1= abs(v[i]-v[i-1])+ memoization_frog_jump(i-1,v,dp);
    if(i-2>=0)jump_2= abs(v[i]-v[i-2])+ memoization_frog_jump(i-2,v,dp);
    return dp[i]=min(jump_1,jump_2);
}

int dynamic_programming_frog_jump(int n,vector<int>&v,vector<int>&dp){
    // Time Complexity:O(N)
    // Space Complexity:O(N)
    if(n>=0)dp[0]=0;
    if(n>=1)dp[1]=abs(v[1]-v[0]);
    for(int i=2;i<=n;i++){
        dp[i]=min(abs(v[i]-v[i-1])+dp[i-1],abs(v[i]-v[i-2])+dp[i-2]);
    }
    return dp[n];
}
int space_optimization(int n,vector<int>&v){
    // Time Complexity:O(N)
    // Space Complexity:O(1)
    if(n==0)return 0;
    if(n==1)return abs(v[1]-v[0]);
    int second_last=0;
    int last=abs(v[1]-v[0]);
    int ans=0;
    for(int i=2;i<=n;i++){
        ans=min(abs(v[i]-v[i-1])+last,abs(v[i]-v[i-2])+second_last);
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
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vector<int> dp(n+1, -1);

    int result_recursive = recursive_frog_jump(n-1,n,v);
    int result_memoization = memoization_frog_jump(n-1,v, dp);
    int result_dynamic = dynamic_programming_frog_jump(n-1,v, dp);
    int result_space_optimization = space_optimization(n-1,v);

    cout << "frog_jump using Recursive: " << result_recursive << endl;
    cout << "frog_jump using Memoization: " << result_memoization << endl;
    cout << "frog_jump using Dynamic Programming: " << result_dynamic << endl;
    cout << "frog_jump using Space Optimization: " << result_space_optimization << endl;

    return 0;
}