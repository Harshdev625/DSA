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

int recursive_Matrix_Chain_Multiplication(int i,int j,vi &v){
    // Time Complexity: O(2^(N^2))
    // Space Complexity: O(N)
    if(i==j)return 0;
    int product = INT_MAX;
    for(int k=i;k<=j-1;k++){
        product=min(product,recursive_Matrix_Chain_Multiplication(i,k,v)+recursive_Matrix_Chain_Multiplication(k+1,j,v)+v[i-1]*v[k]*v[j]);
    }
    return product;
}

int memoization_Matrix_Chain_Multiplication(int i,int j,vi &v,vvi &dp){
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    if(i==j)return dp[i][j]= 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int product = INT_MAX;
    for(int k=i;k<=j-1;k++){
        product=min(product,memoization_Matrix_Chain_Multiplication(i,k,v,dp)+memoization_Matrix_Chain_Multiplication(k+1,j,v,dp)+v[i-1]*v[k]*v[j]);
    }
    return dp[i][j]=product;
}

int dynamic_programming_Matrix_Chain_Multiplication(int n,vi &v){
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    vvi dp(n+1, vi(n+1,0));
    for (int i = n-1; i >=1; i--) {
        for (int j = i+1; j <=n; j++) {
            dp[i][j] = INT_MAX;
            for(int k=i;k<=j-1;k++){
                int product=dp[i][k]+dp[k+1][j]+v[i-1]*v[k]*v[j];
                dp[i][j]=min(product,dp[i][j]);
            }
        }
    }
    return dp[1][n];
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n ;
    vi v(n+1);
    for(int i=0;i<=n;i++)cin>>v[i];
    vvi dp(n+1, vi(n+1,-1));

    int result_recursive = recursive_Matrix_Chain_Multiplication(1,n,v);
    int result_memoization = memoization_Matrix_Chain_Multiplication(1,n,v,dp);
    int result_dynamic = dynamic_programming_Matrix_Chain_Multiplication(n,v);
    
    cout << "Matrix_Chain_Multiplication using Recursive: " << result_recursive << endl;
    cout << "Matrix_Chain_Multiplication using Memoization: " << result_memoization << endl;
    cout << "Matrix_Chain_Multiplication using Dynamic Programming: " << result_dynamic << endl;

    return 0;
}