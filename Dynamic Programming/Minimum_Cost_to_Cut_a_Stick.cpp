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

int recursive_Minimum_Cost_to_Cut_a_Stick(int i,int j,vi &v){
    // Time Complexity: O(2^(N^2))
    // Space Complexity: O(N)
    if(i>j)return 0;
    int cuts = INT_MAX;
    for(int k=i;k<=j;k++){
        cuts=min(cuts,v[j+1]-v[i-1]+ recursive_Minimum_Cost_to_Cut_a_Stick(i,k-1,v)+recursive_Minimum_Cost_to_Cut_a_Stick(k+1,j,v));
    }
    return cuts;
}

int memoization_Minimum_Cost_to_Cut_a_Stick(int i,int j,vi &v,vvi &dp){
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int cuts = INT_MAX;
    for(int k=i;k<=j;k++){
        cuts=min(cuts,v[j+1]-v[i-1]+memoization_Minimum_Cost_to_Cut_a_Stick(i,k-1,v,dp)+memoization_Minimum_Cost_to_Cut_a_Stick(k+1,j,v,dp));
    }
    return dp[i][j]=cuts;
}

int dynamic_programming_Minimum_Cost_to_Cut_a_Stick(int n,vi &v){
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    vvi dp(n+2, vi(n+2,0));
    for (int i = n; i >=1; i--) {
        for (int j = i; j <=n; j++) {
            dp[i][j] = INT_MAX;
            for(int k=i;k<=j;k++){
                int cuts=dp[i][k-1]+dp[k+1][j]+v[j+1]-v[i-1];
                dp[i][j]=min(cuts,dp[i][j]);
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
    int n,k;
    cin >> n >> k;
    vi v(k);
    for(int i=0;i<k;i++)cin>>v[i];
    v.push_back(n);
    v.push_back(0);
    sort(v.begin(),v.end());
    vvi dp(n+2, vi(n+2,-1));

    int result_recursive = recursive_Minimum_Cost_to_Cut_a_Stick(1,k,v);
    int result_memoization = memoization_Minimum_Cost_to_Cut_a_Stick(1,k,v,dp);
    int result_dynamic = dynamic_programming_Minimum_Cost_to_Cut_a_Stick(k,v);
    
    cout << "Minimum_Cost_to_Cut_a_Stick using Recursive: " << result_recursive << endl;
    cout << "Minimum_Cost_to_Cut_a_Stick using Memoization: " << result_memoization << endl;
    cout << "Minimum_Cost_to_Cut_a_Stick using Dynamic Programming: " << result_dynamic << endl;

    return 0;
}