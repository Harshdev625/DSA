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

bool recursive_partition_equal_subset_sum(int index,int k,int & n,vi &v){
    // Time Complexity:O(k^N)
    // Space Complexity:O(N)
    if(k<0)return false;
    if(index==-1){
        if(k==0)return true;
        else return false;
    }
    return recursive_partition_equal_subset_sum(index-1,k-v[index],n,v) | recursive_partition_equal_subset_sum(index-1,k,n,v);
}

bool memoization_partition_equal_subset_sum(int index,int k,vi &v,vvi &dp){
    // Time Complexity:O(N*(Total/2))
    // Space Complexity:O(N*(Total/2))
    if(k<0)return false;
    if(index==-1){
        if(k==0)return dp[index+1][k]=true;
        else return false;
    }
    if(dp[index][k]!=-1)return dp[index][k];
    return dp[index][k]=memoization_partition_equal_subset_sum(index-1,k-v[index],v,dp) | memoization_partition_equal_subset_sum(index-1,k,v,dp);
}

bool dynamic_programming_partition_equal_subset_sum(int &n,int k,vi &v,vvi &dp){
    // Time Complexity:O(N*(Total/2))
    // Space Complexity:O(N*(Total/2))
    for(int i=0;i<=k;i++)dp[0][i]=false;
    for(int i=0;i<=n;i++)dp[i][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]= dp[i-1][j] | (j-v[i-1]>=0?dp[i-1][j-v[i-1]]:false);
        }
    }
    return dp[n][k];
}

bool space_optimization(int &n,int k,vi &v){
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
    return dp[k];
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
    vvi  dp(n+1, vi(total/2 +1,-1));

    bool result_recursive = (total%2==0? recursive_partition_equal_subset_sum(n-1,total/2,n,v) :false);
    bool result_memoization = (total%2==0? memoization_partition_equal_subset_sum(n-1,total/2,v,dp) :false);
    bool result_dynamic = (total%2==0? dynamic_programming_partition_equal_subset_sum(n,total/2,v,dp) :false);
    bool result_space_optimization = (total%2==0? space_optimization(n,total/2,v) :false);

    cout << "partition_equal_subset_sum using Recursive: " << (result_recursive ? "true" : "false") << endl;
    cout << "partition_equal_subset_sum using Memoization: " << (result_memoization ? "true" : "false")<< endl;
    cout << "partition_equal_subset_sum using Dynamic Programming: " << (result_dynamic ?"true" : "false") << endl;
    cout << "partition_equal_subset_sum using Space Optimization: " << (result_space_optimization?"true" : "false") << endl;

    return 0;
}