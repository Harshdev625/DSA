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

int recursive_Longest_Increasing_Subsequence(int i,int n,int j,vi &v){
    // Time Complexity:O(2^N) // Max(n,m)
    // Space Complexity:O(N)
    if(i==n)return 0;
    int nottake = recursive_Longest_Increasing_Subsequence(i+1,n,j,v),take=-1;
    if(j==-1 || v[i]>v[j])take=1+recursive_Longest_Increasing_Subsequence(i+1,n,i,v);
    return max(take,nottake);
}

int memoization_Longest_Increasing_Subsequence(int i,int n,int j,vi &v,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    if(i==n)return 0;
    if(dp[i][j+1]!=-1)return dp[i][j+1];
    int nottake = memoization_Longest_Increasing_Subsequence(i+1,n,j,v,dp),take=0;
    if(j==-1 || v[i]>v[j])take=1+memoization_Longest_Increasing_Subsequence(i+1,n,i,v,dp);
    return dp[i][j+1]=max(take,nottake);
}

int dynamic_programming_Longest_Increasing_Subsequence(int n,vi &v,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    for (int i = 0; i <= n; i++) {
        dp[i][n] = 0;
        dp[i][n-1] = 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[n][i] = 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= -1; j--) {
            int nottake = dp[i + 1][j+1];
            int take = 0;
            if (j==-1 || v[i] > v[j]) {
                take = 1 + max(dp[i + 1][i+1],take);
            }
            dp[i][j+1] = max(take, nottake);
        }
    }
    return dp[0][0];
}

int space_optimization(int n,vi &v){
    // Time Complexity:O(N*M)
    // Space Complexity:O(M)
    vi dp(n+1,0);
    vi t(n+1,0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i - 1; j >= -1; j--) {
            int nottake = dp[j+1];
            int take = 0;
            if (j==-1 || v[i] > v[j]) {
                take = 1 + max(dp[i+1],take);
            }
            t[j+1] = max(take, nottake);
        }
        dp=t;
    }
    return dp[0];
}

int binary_serach(int n, vi&v){
    vi ans;
    ans.push_back(v[0]);
    for(int i=1;i<n;i++){
        if(ans.back()<v[i]){
            ans.push_back(v[i]);
        }
        else{
            int index= lower_bound(ans.begin(),ans.end(),v[i])- ans.begin();
            ans[index]=v[i];
        }
    }
    return ans.size();
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
    vvi dp(n+1, vi(n+1,-1));

    int result_recursive = recursive_Longest_Increasing_Subsequence(0,n,-1,v);
    int result_memoization = memoization_Longest_Increasing_Subsequence(0,n,-1,v,dp);
    int result_dynamic = dynamic_programming_Longest_Increasing_Subsequence(n,v,dp);
    int result_space_optimization = space_optimization(n,v);
    int result_binary_serach = binary_serach(n,v);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<nl;
    }
    cout << "Longest_Increasing_Subsequence using Recursive: " << result_recursive << endl;
    cout << "Longest_Increasing_Subsequence using Memoization: " << result_memoization << endl;
    cout << "Longest_Increasing_Subsequence using Dynamic Programming: " << result_dynamic << endl;
    cout << "Longest_Increasing_Subsequence using Space Optimization: " << result_space_optimization << endl;
    cout << "Longest_Increasing_Subsequence using Binary Search: " << result_binary_serach << endl;

    return 0;
}