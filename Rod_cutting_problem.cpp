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

int recursive_rod_cutting_problem(int i,int total,vi &v){
    // Time Complexity:O(total^N)  
    // Space Complexity:O(N)
    if(i==0){
        return total*v[0];
    }
    return max(((total-i-1>=0) ? v[i]+recursive_rod_cutting_problem(i,total-i-1,v) : 0),recursive_rod_cutting_problem(i-1,total,v));
}

int memoization_rod_cutting_problem(int i,int total,vi &v,vvi &dp){
    // Time Complexity:O(N*total)
    // Space Complexity:O(N*total)
    if (i == 0){
        return total*v[0];
    }
    if(dp[i][total]!=-1)return dp[i][total];
    return dp[i][total]= max(((total-i-1>=0) ? v[i]+memoization_rod_cutting_problem(i,total-i-1,v,dp) : 0 ),memoization_rod_cutting_problem(i-1,total,v,dp));
}

int dynamic_programming_rod_cutting_problem(int n,int& total,vi &v,vvi &dp){
    // Time Complexity:O(N*total)
    // Space Complexity:O(N*total)
    for(int i=0;i<=total;i++){
        dp[0][i]= i*(v[0]);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=total;j++){
            dp[i][j]= max(((j-i-1>=0) ? v[i]+dp[i][j-i-1] : 0),dp[i-1][j]);
        }
    }
    return dp[n][total];
}

int space_optimization(int n,int& total,vi &v){
    // Time Complexity:O(N*total)
    // Space Complexity:O(total)
    vi dp(total+1,0);
    vi t(total+1,0);
    for(int i=0;i<=total;i++){
        dp[i]= i*(v[0]);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=total;j++){
            t[j]= max(((j-i-1>=0) ? v[i]+t[j-i-1] : 0),dp[j]);
        }
        dp = t;
    }
    return dp[total];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n ;
    vi v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    vvi  dp(n,vi(n+1,-1));

    int result_recursive = recursive_rod_cutting_problem(n-1,n,v);
    int result_memoization = memoization_rod_cutting_problem(n-1,n,v,dp);
    int result_dynamic = dynamic_programming_rod_cutting_problem(n-1,n,v,dp);
    int result_space_optimization = space_optimization(n-1,n,v);

    cout << "rod_cutting_problem using Recursive: " << result_recursive << endl;
    cout << "rod_cutting_problem using Memoization: " << result_memoization << endl;
    cout << "rod_cutting_problem using Dynamic Programming: " << result_dynamic << endl;
    cout << "rod_cutting_problem using Space Optimization: " << result_space_optimization << endl;

    return 0;
}