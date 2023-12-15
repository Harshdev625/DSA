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

int recursive_Burst_Balloons(int i,int j,vi &v){
    // Time Complexity: O(2^(N^2))
    // Space Complexity: O(N)
    if(i>j)return 0;
    int cuts = 0;
    for(int k=i;k<=j;k++){
        cuts=max(cuts,v[j+1]*v[i-1]*v[k]+ recursive_Burst_Balloons(i,k-1,v)+recursive_Burst_Balloons(k+1,j,v));
    }
    return cuts;
}

int memoization_Burst_Balloons(int i,int j,vi &v,vvi &dp){
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int cuts = 0;
    for(int k=i;k<=j;k++){
        cuts=max(cuts,v[j+1]*v[i-1]*v[k]+memoization_Burst_Balloons(i,k-1,v,dp)+memoization_Burst_Balloons(k+1,j,v,dp));
    }
    return dp[i][j]=cuts;
}

int dynamic_programming_Burst_Balloons(int n,vi &v){
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    vvi dp(n+2, vi(n+2,0));
    for (int i = n; i >=1; i--) {
        for (int j = i; j <=n; j++) {
            for(int k=i;k<=j;k++){
                int cuts=dp[i][k-1]+dp[k+1][j]+v[j+1]*v[i-1]*v[k];
                dp[i][j]=max(cuts,dp[i][j]);
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
    v[0]=1;
    for(int i=1;i<=n;i++)cin>>v[i];
    v.push_back(1);
    vvi dp(n+2, vi(n+2,-1));

    int result_recursive = recursive_Burst_Balloons(1,n,v);
    int result_memoization = memoization_Burst_Balloons(1,n,v,dp);
    int result_dynamic = dynamic_programming_Burst_Balloons(n,v);
    
    cout << "Burst_Balloons using Recursive: " << result_recursive << endl;
    cout << "Burst_Balloons using Memoization: " << result_memoization << endl;
    cout << "Burst_Balloons using Dynamic Programming: " << result_dynamic << endl;

    return 0;
}