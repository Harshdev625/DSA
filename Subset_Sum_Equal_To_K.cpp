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

bool recursive_subset_sum_equal_to_k(int index,int k,int & n,vi &v){
    // Time Complexity:O(2^N)
    // Space Complexity:O(N)
    if(k<0)return false;
    if(index==-1){
        if(k==0)return true;
        else return false;
    }
    return recursive_subset_sum_equal_to_k(index-1,k-v[index],n,v) | recursive_subset_sum_equal_to_k(index-1,k,n,v);
}

bool memoization_subset_sum_equal_to_k(int index,int k,vi &v,vvi &dp){
    // Time Complexity:O(N*k)
    // Space Complexity:O(N*k)
    if(k<0)return false;
    if(index==-1){
        if(k==0)return dp[index+1][k]=true;
        else return false;
    }
    if(dp[index][k]!=-1)return dp[index][k];
    return dp[index][k]=memoization_subset_sum_equal_to_k(index-1,k-v[index],v,dp) | memoization_subset_sum_equal_to_k(index-1,k,v,dp);
}

bool dynamic_programming_subset_sum_equal_to_k(int &n,int &k,vi &v,vvi &dp){
    // Time Complexity:O(N*k)
    // Space Complexity:O(N*k)
    for(int i=0;i<=k;i++)dp[0][i]=false;
    for(int i=0;i<=n;i++)dp[i][0]=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]= dp[i-1][j] | (j-v[i-1]>=0?dp[i-1][j-v[i-1]]:false);
        }
    }
    return dp[n][k];
}

int space_optimization(int &n,int& k,vi &v){
    // Time Complexity:O(N*k)
    // Space Complexity:O(k)
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
    int n,k;
    cin >> n >> k;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vvi  dp(n+1, vi(k+1,-1));

    bool result_recursive = recursive_subset_sum_equal_to_k(n-1,k,n,v);
    bool result_memoization = memoization_subset_sum_equal_to_k(n-1,k,v,dp);
    bool result_dynamic = dynamic_programming_subset_sum_equal_to_k(n,k,v,dp);
    bool result_space_optimization = space_optimization(n,k,v);

    cout << "subset_sum_equal_to_k using Recursive: " << (result_recursive ? "true" : "false") << endl;
    cout << "subset_sum_equal_to_k using Memoization: " << (result_memoization ? "true" : "false")<< endl;
    cout << "subset_sum_equal_to_k using Dynamic Programming: " << (result_dynamic ?"true" : "false") << endl;
    cout << "subset_sum_equal_to_k using Space Optimization: " << (result_space_optimization?"true" : "false") << endl;

    return 0;
}