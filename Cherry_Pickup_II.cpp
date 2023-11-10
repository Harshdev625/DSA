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

int recursive_cherry_pickup_II_helper(int i,int j,int k,int &n,int &m,vvi &v){
    // Time Complexity:O(3^(M+N))
    // Space Complexity:O(N)
    if(i<0 || j<0 || j>=m || i>=m)return -1e8;
    if(k==n-1){ 
        if(i==j)return v[k][i];
        else return v[k][i]+v[k][j];
    }
    int ans= -1e8;
    for(int p1=-1;p1<=1;p1++){
        for(int p2=-1;p2<=1;p2++){
            if(i==j)max(ans,v[k][i]+recursive_cherry_pickup_II_helper(i+p1,j+p2,k+1,n,m,v));
            else ans= max(ans,v[k][i]+v[k][j]+recursive_cherry_pickup_II_helper(i+p1,j+p2,k+1,n,m,v));
        }
    }
    return ans;
}

int recursive_cherry_pickup_II(int n,int m,vvi &v){
    return recursive_cherry_pickup_II_helper(0,m-1,0,n,m,v);
}

int memoization_cherry_pickup_II(int i,int j,int k,int &n,int &m,vvi&v,vvvi &dp){
    // Time Complexity:O(N*M*M)
    // Space Complexity:O(N*M*M)
    if(i<0 || j<0 || j>=m || i>=m)return -1e8;
    if(k==n-1){ 
        if(i==j)return dp[k][i][j]=v[k][i];
        else return dp[k][i][j]=v[k][i]+v[k][j];
    }
    if(dp[k][i][j]!=-1)return dp[k][i][j];
    int ans= -1e8;
    for(int p1=-1;p1<=1;p1++){
        for(int p2=-1;p2<=1;p2++){
            if(i==j)max(ans,v[k][i]+memoization_cherry_pickup_II(i+p1,j+p2,k+1,n,m,v,dp));
            else ans= max(ans,v[k][i]+v[k][j]+memoization_cherry_pickup_II(i+p1,j+p2,k+1,n,m,v,dp));
        }
    }
    return dp[k][i][j]=ans;
}


int dynamic_programming_cherry_pickup_II(int n,int m,vvi&v,vvvi &dp){
    // Time Complexity:O(N*M*M)
    // Space Complexity:O(N*M*M)
    
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j) dp[n-1][i][j]= v[n-1][i];
            else dp[n-1][i][j]= v[n-1][i] + v[n-1][j];
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                for(int l=-1;l<=1;l++){
                    for(int o=-1;o<=1;o++){
                        if(j+l>=0 && j+l<m && k+o>=0 && k+o<m){
                            if(j==k) dp[i][j][k]=max(dp[i][j][k], v[i][j] + dp[i+1][j+l][k+o]);
                            else dp[i][j][k]=max(dp[i][j][k], v[i][j]+ v[i][k] + dp[i+1][j+l][k+o]);
                        }
                    }
                }
            }
        }
    }
    return dp[0][0][m-1];
}

int space_optimization(int n,int m,vvi&v){
    // Time Complexity:O(N*M*M)
    // Space Complexity:O(M*M)
    vvi dp(m,vi(m,-1));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(i==j) dp[i][j]= v[n-1][i];
            else dp[i][j]= v[n-1][i] + v[n-1][j];
        }
    }

    for(int i=n-2;i>=0;i--){
        vvi t(m,vi(m,0));
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                for(int l=-1;l<=1;l++){
                    for(int o=-1;o<=1;o++){
                        if(j+l>=0 && j+l<m && k+o>=0 && k+o<m){
                            if(j==k) t[j][k]=max(t[j][k], v[i][j] + dp[j+l][k+o]);
                            else t[j][k]=max(t[j][k], v[i][j]+ v[i][k] + dp[j+l][k+o]);
                        }
                    }
                }
                
            }
        }
        dp=t;
    }
    return dp[0][m-1];
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >>m;
    vvi v(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>v[i][j];
    }
    vvvi dp(n, vvi(m,vi(m,-1)));
    int result_recursive = recursive_cherry_pickup_II(n,m,v);
    int result_memoization = memoization_cherry_pickup_II(0,m-1,0,n,m,v,dp);
    int result_dynamic = dynamic_programming_cherry_pickup_II(n,m,v,dp);
    int result_space_optimization = space_optimization(n,m,v);

    cout << "cherry_pickup_II using Recursive: " << result_recursive << nl;
    cout << "cherry_pickup_II using Memoization: " << result_memoization << nl;
    cout << "cherry_pickup_II using Dynamic Programming: " << result_dynamic << nl;
    cout << "cherry_pickup_II using Space Optimization: " << result_space_optimization << nl;

    return 0;
}