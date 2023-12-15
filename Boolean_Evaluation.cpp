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

ll recursive_Boolean_Evaluation(int i,int j,int istrue,string &s){
    // Time Complexity: O(2^(N^2))
    // Space Complexity: O(N)
    if(i>j)return 0;
    if(i==j){
        if(istrue==1)return s[i]=='T';
        else return s[i]=='F';
    }
    ll ans = 0;
    for(int k=i+1;k<=j-1;k+=2){
        ll lefttrue= recursive_Boolean_Evaluation(i,k-1,1,s);
        ll leftfalse= recursive_Boolean_Evaluation(i,k-1,0,s);
        ll righttrue= recursive_Boolean_Evaluation(k+1,j,1,s);
        ll rightfalse= recursive_Boolean_Evaluation(k+1,j,0,s);
        if(s[k]=='&'){
            if(istrue)ans=(ans%MOD+(lefttrue*righttrue)%MOD)%MOD;
            else {
                ans=(ans%MOD+(leftfalse*rightfalse)%MOD)%MOD;
                ans=(ans%MOD+(lefttrue*rightfalse)%MOD)%MOD;
                ans=(ans%MOD+(leftfalse*righttrue)%MOD)%MOD;
            }
        }
        else if(s[k]=='|'){
            if(istrue){
                ans=(ans%MOD+(lefttrue*righttrue)%MOD)%MOD;
                ans=(ans%MOD+(lefttrue*rightfalse)%MOD)%MOD;
                ans=(ans%MOD+(leftfalse*righttrue)%MOD)%MOD;
            }
            else{
                ans=(ans%MOD+(leftfalse*rightfalse)%MOD)%MOD;
            }
        }
        else{
            if(istrue){
                ans=(ans%MOD+(lefttrue*rightfalse)%MOD)%MOD;
                ans=(ans%MOD+(leftfalse*righttrue)%MOD)%MOD;
            }
            else{
                ans=(ans%MOD+(lefttrue*righttrue)%MOD)%MOD;
                ans=(ans%MOD+(leftfalse*rightfalse)%MOD)%MOD;
            }
        }
    }
    return ans;
}

ll memoization_Boolean_Evaluation(int i,int j,int istrue,string &s,vvvi &dp){
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    if(i>j)return 0;
    if(i==j){
        if(istrue==1)return s[i]=='T';
        else return s[i]=='F';
    }
    if(dp[i][j][istrue]!=-1)return dp[i][j][istrue];
    ll ans = 0;
    for(int k=i+1;k<=j-1;k+=2){
        ll lefttrue= memoization_Boolean_Evaluation(i,k-1,1,s,dp);
        ll leftfalse= memoization_Boolean_Evaluation(i,k-1,0,s,dp);
        ll righttrue= memoization_Boolean_Evaluation(k+1,j,1,s,dp);
        ll rightfalse= memoization_Boolean_Evaluation(k+1,j,0,s,dp);
        if(s[k]=='&'){
            if(istrue)ans=(ans%MOD+(lefttrue*righttrue)%MOD)%MOD;
            else {
                ans=(ans%MOD+(leftfalse*rightfalse)%MOD)%MOD;
                ans=(ans%MOD+(lefttrue*rightfalse)%MOD)%MOD;
                ans=(ans%MOD+(leftfalse*righttrue)%MOD)%MOD;
            }
        }
        else if(s[k]=='|'){
            if(istrue){
                ans=(ans%MOD+(lefttrue*righttrue)%MOD)%MOD;
                ans=(ans%MOD+(lefttrue*rightfalse)%MOD)%MOD;
                ans=(ans%MOD+(leftfalse*righttrue)%MOD)%MOD;
            }
            else{
                ans=(ans%MOD+(leftfalse*rightfalse)%MOD)%MOD;
            }
        }
        else{
            if(istrue){
                ans=(ans%MOD+(lefttrue*rightfalse)%MOD)%MOD;
                ans=(ans%MOD+(leftfalse*righttrue)%MOD)%MOD;
            }
            else{
                ans=(ans%MOD+(lefttrue*righttrue)%MOD)%MOD;
                ans=(ans%MOD+(leftfalse*rightfalse)%MOD)%MOD;
            }
        }
    }
    
    return dp[i][j][istrue]=ans;
}

int dynamic_programming_Boolean_Evaluation(int n,string &s){
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    vvvi dp(n,vvi(n, vi(2,0)));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n - 1; j++) {
            if (i > j) continue;
            for(int istrue=0;istrue<=1;istrue++){
                if(i==j){
                    if(istrue==1) dp[i][j][istrue] = s[i]=='T';
                    else dp[i][j][istrue] = s[i]=='F';
                    continue;
                }
                ll ans=0;
                for(int k=i+1;k<=j-1;k+=2){
                    ll lefttrue= dp[i][k-1][1];
                    ll leftfalse= dp[i][k-1][0];
                    ll righttrue= dp[k+1][j][1];
                    ll rightfalse= dp[k+1][j][0];
                    if(s[k]=='&'){
                        if(istrue)ans=(ans%MOD+(lefttrue*righttrue)%MOD)%MOD;
                        else {
                            ans=(ans%MOD+(leftfalse*rightfalse)%MOD)%MOD;
                            ans=(ans%MOD+(lefttrue*rightfalse)%MOD)%MOD;
                            ans=(ans%MOD+(leftfalse*righttrue)%MOD)%MOD;
                        }
                    }
                    else if(s[k]=='|'){
                        if(istrue){
                            ans=(ans%MOD+(lefttrue*righttrue)%MOD)%MOD;
                            ans=(ans%MOD+(lefttrue*rightfalse)%MOD)%MOD;
                            ans=(ans%MOD+(leftfalse*righttrue)%MOD)%MOD;
                        }
                        else{
                            ans=(ans%MOD+(leftfalse*rightfalse)%MOD)%MOD;
                        }
                    }
                    else{
                        if(istrue){
                            ans=(ans%MOD+(lefttrue*rightfalse)%MOD)%MOD;
                            ans=(ans%MOD+(leftfalse*righttrue)%MOD)%MOD;
                        }
                        else{
                            ans=(ans%MOD+(lefttrue*righttrue)%MOD)%MOD;
                            ans=(ans%MOD+(leftfalse*rightfalse)%MOD)%MOD;
                        }
                    }
                }
                dp[i][j][istrue]=ans;
            }
        }
    }
    return dp[0][n-1][1];
}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n=s.size();
    vvvi dp(n+1,vvi(n+1, vi(2,-1)));

    ll result_recursive = recursive_Boolean_Evaluation(0,n-1,1,s);
    ll result_memoization = memoization_Boolean_Evaluation(0,n-1,1,s,dp);
    ll result_dynamic = dynamic_programming_Boolean_Evaluation(n,s);
    
    cout << "Boolean_Evaluation using Recursive: " << result_recursive << endl;
    cout << "Boolean_Evaluation using Memoization: " << result_memoization << endl;
    cout << "Boolean_Evaluation using Dynamic Programming: " << result_dynamic << endl;

    return 0;
}