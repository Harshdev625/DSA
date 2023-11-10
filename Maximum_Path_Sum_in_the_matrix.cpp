//https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998
#include <bits/stdc++.h>
using namespace std;
#define ll long long  
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int> 
#define vvi vector<vector<int>>
#define vll vector<long long>
#define mii map<int, int>
#define pb push_back
#define f second_last
#define s last
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9

int N=0;
int M=0;

int recursive_maximum_path_sum_in_the_matrix_helper(int i,int j,vvi &v){
    // Time Complexity: O(M * 3^M)
    // Space Complexity: O(M)
    if(i<0 || j<0 || i>=N || j>=M)return INT_MIN;
    if(i==0)return v[i][j];
    return v[i][j]+max({recursive_maximum_path_sum_in_the_matrix_helper(i-1,j-1,v),recursive_maximum_path_sum_in_the_matrix_helper(i-1,j,v),recursive_maximum_path_sum_in_the_matrix_helper(i-1,j+1,v)});
}

int recursive_maximum_path_sum_in_the_matrix(int i,int k,vvi &v){
    // Time Complexity:O(2^(M+N))
    // Space Complexity:O(N)
    int ans=INT_MIN;
    for(int j=0;j<M;j++){
        ans=max(recursive_maximum_path_sum_in_the_matrix_helper(i,j,v),ans);
    }
    return ans;
}

int memoization_maximum_path_sum_in_the_matrix_helper(int i,int j,vvi&v,vvi &dp){
    if(i<0 || j<0 || i>=N || j>=M)return INT_MIN;
    if(i==0)dp[i][j]=v[i][j];
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=v[i][j]+max({memoization_maximum_path_sum_in_the_matrix_helper(i-1,j-1,v,dp),memoization_maximum_path_sum_in_the_matrix_helper(i-1,j,v,dp),memoization_maximum_path_sum_in_the_matrix_helper(i-1,j+1,v,dp)});
}

int memoization_maximum_path_sum_in_the_matrix(int i,int j,vvi&v,vvi &dp){
    // Time Complexity: O(N*M)
    // Space Complexity: O(N*M)
    int ans=INT_MIN;
    for(int j=0;j<M;j++){
        ans=max(memoization_maximum_path_sum_in_the_matrix_helper(i,j,v,dp),ans);
    }
    return ans;
}

int dynamic_programming_maximum_path_sum_in_the_matrix(int n,int m,vvi&v,vvi &dp){
    // Time Complexity: O(N*M)
    // Space Complexity: O(N*M)
    dp=v;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j]=v[i][j]+dp[i-1][j];
            if(j+1<m)dp[i][j]=max(dp[i][j],v[i][j]+dp[i-1][j+1]);
            if(j>0)dp[i][j]=max(dp[i][j],v[i][j]+dp[i-1][j-1]);
        }
    }
    return *max_element(dp[n-1].begin(),dp[n-1].end());
}

int space_optimization(int n,int m,vvi&v){
    // Time Complexity: O(N*M)
    // Space Complexity: O(M)
    vi dp=v[0];
    for(int i=1;i<n;i++){
        vi t(m);
        for(int j=0;j<m;j++){
            t[j]=v[i][j]+dp[j];
            if(j+1<m)t[j]=max(t[j],v[i][j]+dp[j+1]);
            if(j>0)t[j]=max(t[j],v[i][j]+dp[j-1]);
        }
        dp=t;
    }
    return *max_element(dp.begin(),dp.end());
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >>m;
    N=n;
    M=m;
    vvi v(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>v[i][j];
    }
    vvi dp(n, vi(m,-1));
    int result_recursive = recursive_maximum_path_sum_in_the_matrix(n-1,m-1,v);
    int result_memoization = memoization_maximum_path_sum_in_the_matrix(n-1,m-1,v,dp);
    int result_dynamic = dynamic_programming_maximum_path_sum_in_the_matrix(n,m,v,dp);
    int result_space_optimization = space_optimization(n,m,v);

    cout << "maximum_path_sum_in_the_matrix using Recursive: " << result_recursive << nl;
    cout << "maximum_path_sum_in_the_matrix using Memoization: " << result_memoization << nl;
    cout << "maximum_path_sum_in_the_matrix using Dynamic Programming: " << result_dynamic << nl;
    cout << "maximum_path_sum_in_the_matrix using Space Optimization: " << result_space_optimization << nl;

    return 0;
}