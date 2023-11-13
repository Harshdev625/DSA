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

int recursive_longest_common_subsequence(string a,string b,int n,int m){
    // Time Complexity:O(2^N) // Max(n,m)
    // Space Complexity:O(N)
    if(n<0 || m<0)return 0;
    return max(a[n]==b[m]?1+ recursive_longest_common_subsequence(a,b,n-1,m-1):0, max(recursive_longest_common_subsequence(a,b,n-1,m),recursive_longest_common_subsequence(a,b,n,m-1)));
}

int memoization_longest_common_subsequence(string a,string b,int n,int m,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    if(n<0 || m<0)return 0;
    if(dp[n][m]!=-1)return dp[n][m];
    int nottake=max(memoization_longest_common_subsequence(a,b,n,m-1,dp),memoization_longest_common_subsequence(a,b,n-1,m,dp));
    int take= (a[n]==b[m]?1+memoization_longest_common_subsequence(a,b,n-1,m-1,dp):0);
    return dp[n][m]=max(take,nottake);
}

int dynamic_programming_longest_common_subsequence(string a,string b,int n,int m,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]= max(max(dp[i-1][j],dp[i][j-1]),(a[i-1]==b[j-1]? 1 +dp[i-1][j-1]:0));
        }
    }
    return dp[n][m];
}

int space_optimization(string a,string b,int n,int m){
    // Time Complexity:O(N*M)
    // Space Complexity:O(M)
    vi dp(m+1,0);
    vi t(m+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            t[j]= max(max(dp[j],t[j-1]),(a[i-1]==b[j-1]? 1 +dp[j-1]:0));
        }
        dp=t;
    }
    return dp[m];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a,b;
    cin >> a >> b ;
    int n= a.size();
    int m= b.size();
    vvi dp(n+1, vi(m+1,-1));

    int result_recursive = recursive_longest_common_subsequence(a,b,n-1,m-1);
    int result_memoization = memoization_longest_common_subsequence(a,b,n-1,m-1,dp);
    int result_dynamic = dynamic_programming_longest_common_subsequence(a,b,n,m,dp);
    int result_space_optimization = space_optimization(a,b,n,m);

    cout << "longest_common_subsequence using Recursive: " << result_recursive << endl;
    cout << "longest_common_subsequence using Memoization: " << result_memoization << endl;
    cout << "longest_common_subsequence using Dynamic Programming: " << result_dynamic << endl;
    cout << "longest_common_subsequence using Space Optimization: " << result_space_optimization << endl;

    return 0;
}