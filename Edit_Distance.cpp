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

int recursive_Edit_Distance(string a,string b,int m,int n){
    // Time Complexity:O(2^(max(n, m)))
    // Space Complexity:O(N)
    if(n<0)return m+1;
    if(m<0)return n+1;
    if(a[m]==b[n]) return recursive_Edit_Distance(a,b,m-1,n-1);
    int a1=1+recursive_Edit_Distance(a,b,m-1,n-1);
    int b1=1+recursive_Edit_Distance(a,b,m-1,n);
    int c1=1+recursive_Edit_Distance(a,b,m,n-1);
    return min(a1, min(b1, c1));
}

int memoization_Edit_Distance(string a,string b,int m,int n,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    if(n<0)return m+1;
    if(m<0)return n+1;
    if(dp[m][n]!=INT_MAX)return dp[m][n];
    if(a[m]==b[n]) return dp[m][n]=memoization_Edit_Distance(a,b,m-1,n-1,dp);
    int a1=1+memoization_Edit_Distance(a,b,m-1,n-1,dp);
    int b1=1+memoization_Edit_Distance(a,b,m-1,n,dp);
    int c1=1+memoization_Edit_Distance(a,b,m,n-1,dp);
    return dp[m][n]=min(a1, min(b1, c1));
}

int dynamic_programming_Edit_Distance(string a, string b, int m, int n, vvi &dp) {
    // Time Complexity: O(N*M)
    // Space Complexity: O(N*M)
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
        }
    }
    return dp[m][n];
}

int space_optimization(string a,string b,int m, int n) {
    // Time Complexity: O(N*M)
    // Space Complexity: O(M)
    vi dp(n + 1, 0);
    for(int i=0;i<=n;i++)dp[i]=i;
    vi t(n+1,0);
    for (int i = 1; i<=m; i++) {
        t[0]=i;
        for (int j = 1; j <=n; j++) {
            if (a[i - 1] == b[j - 1]) {
                t[j] = dp[j - 1];
            } else {
                t[j] = 1 + min(dp[j - 1], min(dp[j], t[j - 1]));
            }
        }
        dp=t;
    }
    return dp[n];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a,b;
    cin >> a >> b;
    int m= a.size();
    int n= b.size();
    vvi dp(m+1, vi(n+1,INT_MAX));
    int result_recursive = recursive_Edit_Distance(a,b,m-1,n-1);
    int result_memoization = memoization_Edit_Distance(a,b,m-1,n-1,dp);
    int result_dynamic = dynamic_programming_Edit_Distance(a,b,m,n,dp);
    int result_space_optimization = space_optimization(a,b,m,n);

    cout << "Edit_Distance using Recursive: " << result_recursive << endl;
    cout << "Edit_Distance using Memoization: " << result_memoization << endl;
    cout << "Edit_Distance using Dynamic Programming: " << result_dynamic << endl;
    cout << "Edit_Distance using Space Optimization: " << result_space_optimization << endl;

    return 0;
}