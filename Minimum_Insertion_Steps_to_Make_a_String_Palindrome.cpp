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

int recursive_Minimum_Insertion_Steps_to_Make_a_String_Palindrome(string a,int n,int m){
    // Time Complexity:O(2^(max(n, m)))
    // Space Complexity:O(N)
    if(n>=m)return 0;
    if(a[n]==a[m]) return recursive_Minimum_Insertion_Steps_to_Make_a_String_Palindrome(a,n+1,m-1);
    return 1+min(recursive_Minimum_Insertion_Steps_to_Make_a_String_Palindrome(a,n,m-1),recursive_Minimum_Insertion_Steps_to_Make_a_String_Palindrome(a,n+1,m));
}

int memoization_Minimum_Insertion_Steps_to_Make_a_String_Palindrome(string a,int n,int m,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    if(n>=m)return 0;
    if(dp[n][m]!=INT_MAX)return dp[n][m];
    if(a[n]==a[m]) return memoization_Minimum_Insertion_Steps_to_Make_a_String_Palindrome(a,n+1,m-1,dp);
    return dp[n][m]=1+min(memoization_Minimum_Insertion_Steps_to_Make_a_String_Palindrome(a,n,m-1,dp),memoization_Minimum_Insertion_Steps_to_Make_a_String_Palindrome(a,n+1,m,dp));
}

int dynamic_programming_Minimum_Insertion_Steps_to_Make_a_String_Palindrome(string a,int n,int m,vvi &dp){
    // Time Complexity:O(N*M)
    // Space Complexity:O(N*M)
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n-i;j++){
            int k=j+i-1;
            if(j==k)dp[j][k]=0;
            else if(a[j]==a[k])dp[j][k]=dp[j+1][k-1];
            else dp[j][k]=1+min(dp[j+1][k],dp[j][k-1]);
        }
    }
    return dp[0][n-1];
}

int space_optimization(string a, int m) {
    // Time Complexity: O(N*M)
    // Space Complexity: O(M)
    vi dp(m + 1, 0);

    for (int i = m - 1; i >= 0; i--) {
        int prev = 0;
        for (int j = i; j < m; j++) {
            int temp = dp[j];
            if (i == j) {
                dp[j] = 0;
            } else if (a[i] == a[j]) {
                dp[j] = prev;
            } else {
                dp[j] = 1 + min(dp[j], dp[j - 1]);
            }
            prev = temp;
        }
    }

    return dp[m - 1];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a,b;
    cin >> a;
    int m= a.size();
    vvi dp(m+1, vi(m+1,INT_MAX));
    int result_recursive = recursive_Minimum_Insertion_Steps_to_Make_a_String_Palindrome(a,0,m-1);
    int result_memoization = memoization_Minimum_Insertion_Steps_to_Make_a_String_Palindrome(a,0,m-1,dp);
    int result_dynamic = dynamic_programming_Minimum_Insertion_Steps_to_Make_a_String_Palindrome(a,m,m,dp);
    int result_space_optimization = space_optimization(a,m);

    cout << "Minimum_Insertion_Steps_to_Make_a_String_Palindrome using Recursive: " << result_recursive << endl;
    cout << "Minimum_Insertion_Steps_to_Make_a_String_Palindrome using Memoization: " << result_memoization << endl;
    cout << "Minimum_Insertion_Steps_to_Make_a_String_Palindrome using Dynamic Programming: " << result_dynamic << endl;
    cout << "Minimum_Insertion_Steps_to_Make_a_String_Palindrome using Space Optimization: " << result_space_optimization << endl;

    return 0;
}