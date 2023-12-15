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

bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int recursive_Palindrome_Partitioning_II(int i,int n,string &s){
    // Time Complexity: O(2^(N^2))
    // Space Complexity: O(N)
    if(i>n)return 0;
    int mini = INT_MAX;
    for(int k=i;k<=n;k++){
        if(isPalindrome(i,k,s)){
            mini=min(mini,1+recursive_Palindrome_Partitioning_II(k+1,n,s));
        }
    }
    return mini;
}

int memoization_Palindrome_Partitioning_II(int i,int n,string &s,vi &dp){
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    if(i>n)return 0;
    if(dp[i]!=-1)return dp[i];
    int mini = INT_MAX;
    for(int k=i;k<=n;k++){
        if(isPalindrome(i,k,s)){
            mini=min(mini,1+memoization_Palindrome_Partitioning_II(k+1,n,s,dp));
        }
    }
    return dp[i]=mini;
}

int dynamic_programming_Palindrome_Partitioning_II(int n,string &s){
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    vi dp(n+1,0);
    for (int i = n-1; i >=0; i--) {
        int mini = INT_MAX;
        for(int k=i;k<n;k++){
            if(isPalindrome(i,k,s)){
                mini=min(mini,1+dp[k+1]);
            }
        }
        dp[i]= mini;
    }
    return dp[0]-1;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s ;
    int n=s.size();
    vi dp(n+1,-1);

    int result_recursive = recursive_Palindrome_Partitioning_II(0,n-1,s)-1;
    int result_memoization = memoization_Palindrome_Partitioning_II(0,n-1,s,dp)-1;
    int result_dynamic = dynamic_programming_Palindrome_Partitioning_II(n,s);
    
    cout << "Palindrome_Partitioning_II using Recursive: " << result_recursive << endl;
    cout << "Palindrome_Partitioning_II using Memoization: " << result_memoization << endl;
    cout << "Palindrome_Partitioning_II using Dynamic Programming: " << result_dynamic << endl;

    return 0;
}