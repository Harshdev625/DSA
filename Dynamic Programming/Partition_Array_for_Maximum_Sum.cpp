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

int recursive_Partition_Array_for_Maximum_Sum(int i,int n,int k,vi &v){
    // Time Complexity: O(2^(N*K))
    // Space Complexity: O(N)
    if(i>n)return 0;
    int maxi = 0;
    int len=0;
    int maxele=0;
    for(int j=1;j<=k;j++){
        if(i+j<=n){
            len++;
            maxele=max(maxele,v[i+j-1]);
            maxi=max(maxi,maxele*len+ recursive_Partition_Array_for_Maximum_Sum(i+j,n,k,v));
        }
    }
    return maxi;
}

int memoization_Partition_Array_for_Maximum_Sum(int i,int n,int k,vi &v,vi &dp){
    // Time Complexity: O(N*K)
    // Space Complexity: O(N)
    if(i>n)return 0;
    if(dp[i]!=-1)return dp[i];
    int maxi = 0;
    int len=0;
    int maxele=0;
    for(int j=1;j<=k;j++){
        if(i+j<=n){
            len++;
            maxele=max(maxele,v[i+j-1]);
            maxi=max(maxi,maxele*len+ memoization_Partition_Array_for_Maximum_Sum(i+j,n,k,v,dp));
        }
    }
    return dp[i]=maxi;
}

int dynamic_programming_Partition_Array_for_Maximum_Sum(int n,int k,vi &v){
    // Time Complexity: O(N*K)
    // Space Complexity: O(N)
    vi dp(n+1,0);
    for (int i = n-1; i>=0; i--) {
        int maxi = 0;
        int len=0;
        int maxele=0;
        for(int j=1;j<=k;j++){
            if(i+j<=n){
                len++;
                maxele=max(maxele,v[i+j-1]);
                maxi=max(maxi,maxele*len+ dp[i+j]);
            }
            dp[i]=maxi;
        }
    }
    return dp[0];
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
    vi dp(n+1,-1);

    int result_recursive = recursive_Partition_Array_for_Maximum_Sum(0,n,k,v);
    int result_memoization = memoization_Partition_Array_for_Maximum_Sum(0,n,k,v,dp);
    int result_dynamic = dynamic_programming_Partition_Array_for_Maximum_Sum(n,k,v);
    
    cout << "Partition_Array_for_Maximum_Sum using Recursive: " << result_recursive << endl;
    cout << "Partition_Array_for_Maximum_Sum using Memoization: " << result_memoization << endl;
    cout << "Partition_Array_for_Maximum_Sum using Dynamic Programming: " << result_dynamic << endl;

    return 0;
}