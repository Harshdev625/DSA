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

int recursive_longest_common_substring(string a,string b,int n,int m,int count){
    // Time Complexity:O(2^N) // Max(n,m)
    // Space Complexity:O(N)
    if(n==0 || m==0)return count;
    if(a[n-1]==b[m-1]) count= recursive_longest_common_substring(a,b,n-1,m-1,count+1);
    count= max(count, max(recursive_longest_common_substring(a,b,n,m-1,0),recursive_longest_common_substring(a,b,n-1,m,0)));
    return count;
}

int memoization_longest_common_substring(string a,string b,int n,int m,int count,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    if(n<0 || m<0)return count;
    if(dp[n][m]!=INT_MIN)return dp[n][m];
    if(a[n]==b[m]) count= memoization_longest_common_substring(a,b,n-1,m-1,count+1,dp);
    count= max(count, max(memoization_longest_common_substring(a,b,n,m-1,0,dp),memoization_longest_common_substring(a,b,n-1,m,0,dp)));
    return dp[n][m]=count;
}

int dynamic_programming_longest_common_substring(string a,string b,int n,int m,vvi &dp){
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
            if(a[i-1]==b[j-1])dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=0;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,*max_element(dp[i].begin(),dp[i].end()));
    }
    return ans;
}

int space_optimization(string a,string b,int n,int m){
    // Time Complexity:O(N*M)
    // Space Complexity:O(M)
    vi dp(m+1,0);
    vi t(m+1,0);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1])t[j]=1+dp[j-1];
            else t[j]=0;
        }
        dp=t;
        ans=max(ans,*max_element(dp.begin(),dp.end()));
    }
    return ans;
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
    vvi dp(n+1, vi(m+1,INT_MIN));

    int result_recursive = recursive_longest_common_substring(a,b,n,m,0);
    int result_memoization = memoization_longest_common_substring(a,b,n-1,m-1,0,dp);
    int result_dynamic = dynamic_programming_longest_common_substring(a,b,n,m,dp);
    int result_space_optimization = space_optimization(a,b,n,m);

    cout << "longest_common_substring using Recursive: " << result_recursive << endl;
    cout << "longest_common_substring using Memoization: " << result_memoization << endl;
    cout << "longest_common_substring using Dynamic Programming: " << result_dynamic << endl;
    cout << "longest_common_substring using Space Optimization: " << result_space_optimization << endl;

    return 0;
}