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

string recursive_print_longest_common_subsequence(string a,string b,int n,int m){
    // Time Complexity:O(2^N) // Max(n,m)
    // Space Complexity:O(N)
    if(n<0 || m<0)return "";
    string s1,s2,s3;
    if(a[n]==b[m]){
        s1.push_back(a[n]);
        s1+=recursive_print_longest_common_subsequence(a,b,n-1,m-1);
    }
    else{
        s2+= recursive_print_longest_common_subsequence(a,b,n-1,m);
        s3+= recursive_print_longest_common_subsequence(a,b,n,m-1);
    }
    int a1=s1.size(),b1=s2.size(),c1=s3.size();
    return a1>=b1 && a1>=c1? s1 : b1>=a1 && b1>=c1 ? s2 :s3;
}

int memoization_print_longest_common_subsequence_helper(string a,string b,int n,int m,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    if (n <= 0 || m <= 0)return 0;
    if(dp[n][m]!=-1)return dp[n][m];
    int nottake=max(memoization_print_longest_common_subsequence_helper(a,b,n,m-1,dp),memoization_print_longest_common_subsequence_helper(a,b,n-1,m,dp));
    int take= (a[n-1]==b[m-1]?1+memoization_print_longest_common_subsequence_helper(a,b,n-1,m-1,dp):0);
    return dp[n][m]=max(take,nottake);
}

string memoization_print_longest_common_subsequence(string a,string b,int n,int m,vvi &dp){
    int a1= memoization_print_longest_common_subsequence_helper(a,b,n,m,dp);
    string ans;
    int i=n,j=m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
string dynamic_programming_print_longest_common_subsequence(string a,string b,int n,int m,vvi &dp){
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
    string ans;
    int i=n,j=m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            ans.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    string a,b;
    cin >> a >> b ;
    vvi dp(n+1, vi(m+1,-1));

    string result_recursive = recursive_print_longest_common_subsequence(a,b,n-1,m-1);
    reverse(result_recursive.begin(),result_recursive.end());
    string result_memoization = memoization_print_longest_common_subsequence(a,b,n,m,dp);
    string result_dynamic = dynamic_programming_print_longest_common_subsequence(a,b,n,m,dp);

    cout << "print_longest_common_subsequence using Recursive: " << result_recursive << endl;
    cout << "print_longest_common_subsequence using Memoization: " << result_memoization << endl;
    cout << "print_longest_common_subsequence using Dynamic Programming: " << result_dynamic << endl;

    return 0;
}