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

int recursive_count_subsets_with_sum_K(int index,int k,int & n,vi &v){
    // Time Complexity:O(k^N)
    // Space Complexity:O(N)
    if(k==0)return 1;
    if(k<0 || index==-1)return 0;
    return (recursive_count_subsets_with_sum_K(index-1,k-v[index],n,v)%MOD+recursive_count_subsets_with_sum_K(index-1,k,n,v)%MOD)%MOD;
}

int memoization_count_subsets_with_sum_K(int index,int k,vi &v,vvi &dp){
    // Time Complexity:O(N*k)
    // Space Complexity:O(N*k)
    if(k<0) return 0;
    if(k==0) return 1;
    if(index==0) return v[0]==k;
    if(dp[index][k]!=-1)return dp[index][k];
    return dp[index][k]=(memoization_count_subsets_with_sum_K(index-1,k-v[index],v,dp)%MOD+memoization_count_subsets_with_sum_K(index-1,k,v,dp)%MOD)%MOD;
}

int dynamic_programming_count_subsets_with_sum_K(int n,int& k,vi &v,vvi &dp){
    // Time Complexity:O(N*k)
    // Space Complexity:O(N*k)
    for(int i=0;i<=k;i++)dp[0][i]=0;
    for(int i=0;i<=n;i++)dp[i][0]=1;
    if(v[0]<=k)dp[0][v[0]]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=(dp[i-1][j]%MOD+(j-v[i]>=0?dp[i-1][j-v[i]]:0)%MOD)%MOD;
        }
    }
    return dp[n][k];
}

int space_optimization(int n,int& k,vi &v){
    // Time Complexity:O(N*k)
    // Space Complexity:O(k)
    vi dp(k+1,0);
    dp[0]=1;
    if(v[0]<=k)dp[v[0]]=1;
    for(int i=1;i<=n;i++){
        vi t(k+1,0);
        t[0]=1;
        for(int j=1;j<=k;j++){
            t[j]=(dp[j]%MOD+(j-v[i]>=0?dp[j-v[i]]:0)%MOD)%MOD;
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
    vvi dp(n,vi(k+1,-1));

    int result_recursive = recursive_count_subsets_with_sum_K(n-1,k,n,v);
    int result_memoization = memoization_count_subsets_with_sum_K(n-1,k,v,dp);
    int result_dynamic = dynamic_programming_count_subsets_with_sum_K(n-1,k,v,dp);
    int result_space_optimization = space_optimization(n-1,k,v);

    cout << "count_subsets_with_sum_K using Recursive: " << result_recursive << endl;
    cout << "count_subsets_with_sum_K using Memoization: " << result_memoization << endl;
    cout << "count_subsets_with_sum_K using Dynamic Programming: " << result_dynamic << endl;
    cout << "count_subsets_with_sum_K using Space Optimization: " << result_space_optimization << endl;

    return 0;
}