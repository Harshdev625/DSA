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
#define f second_last
#define s last
#define nl "\n"
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9

int recursive_array_partition_with_minimum_difference(int i,int k,int n,vi &v,int & total){
    // Time Complexity:O(k^N)
    // Space Complexity:O(N)
    if(i==-1){
        return abs(total-2*k);
    }
    return min(recursive_array_partition_with_minimum_difference(i-1,k+v[i],n-1,v,total) ,recursive_array_partition_with_minimum_difference(i-1,k,n,v,total));
}

int memoization_array_partition_with_minimum_difference_helper(int i,int k,vi &v,vvi &dp){
    // Time Complexity:O(N*(Total/2))
    // Space Complexity:O(N*(Total/2))
    if(k<0)return 0;
    if(i==-1){
        if(k==0)return dp[i+1][k]=1;
        else return 0;
    }
    if(dp[i][k]!=-1)return dp[i][k];
    return dp[i][k]=memoization_array_partition_with_minimum_difference_helper(i-1,k-v[i],v,dp) | memoization_array_partition_with_minimum_difference_helper(i-1,k,v,dp);
}

int memoization_array_partition_with_minimum_difference(int n,int k,vi &v,vvi &dp,int &total){
    for(int i=0;i<=total;i++)int calculate= memoization_array_partition_with_minimum_difference_helper(n,i,v,dp);
    int ans=INT_MAX;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=total;j++)cout<<dp[i][j]<<" ";
        cout<<nl;
    }
    for(int i=0;i<=k;i++){
        if(dp[n][i])ans=min(abs(total-2*i),ans);
    }
    return ans;
}

int dynamic_programming_array_partition_with_minimum_difference(int &n,int k,vi &v,vvi &dp,int &total){
    // Time Complexity:O(N*(Total/2))
    // Space Complexity:O(N*(Total/2))
    for(int i=0;i<=k;i++)dp[0][i]=0;
    for(int i=0;i<=n;i++)dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]= dp[i-1][j] | (j-v[i-1]>=0?dp[i-1][j-v[i-1]]:false);
        }
    }

    int ans=INT_MAX;
    for(int i=0;i<=k;i++){
        if(dp[n][i])ans=min(abs(total-2*i),ans);
    }
    return ans;
}

int space_optimization(int &n,int k,vi &v,int &total){
    // Time Complexity:O(N*(Total/2))
    // Space Complexity:O(Total/2)
    vi dp(k+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        vi t(k+1,0);
        t[0]=1;
        for(int j=1;j<=k;j++){
            t[j]= dp[j] | (j-v[i-1]>=0?dp[j-v[i-1]]:0);
        }
        dp=t;
    }
    int ans=INT_MAX;
    for(int i=0;i<=k;i++){
        if(dp[i])ans=min(abs(total-2*i),ans);
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
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int total= accumulate(v.begin(),v.end(),0);
    vvi  dp(n+1, vi(total +1,-1));

    int result_recursive = recursive_array_partition_with_minimum_difference(n-1,0,n,v,total) ;
    int result_memoization = memoization_array_partition_with_minimum_difference(n-1,total,v,dp,total) ;
    int result_dynamic = dynamic_programming_array_partition_with_minimum_difference(n,total/2,v,dp,total) ;
    int result_space_optimization = space_optimization(n,total/2,v,total) ;

    cout << "array_partition_with_minimum_difference using Recursive: " << result_recursive  << endl;
    cout << "array_partition_with_minimum_difference using Memoization: " << result_memoization << endl;
    cout << "array_partition_with_minimum_difference using Dynamic Programming: " << result_dynamic  << endl;
    cout << "array_partition_with_minimum_difference using Space Optimization: " << result_space_optimization << endl;

    return 0;
}