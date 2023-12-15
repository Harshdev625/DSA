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

int countSquares(vector < vector < int >> & matrix) {
    vector < vector < int >> ans = matrix;;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j]) ans[i][j] = 1 + min({
                ans[i - 1][j - 1],
                ans[i][j - 1],
                ans[i - 1][j]
            });
            else ans[i][j] = 0;
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        res += accumulate(ans[i].begin(), ans[i].end(), 0);
    }
    return res;
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vvi v(n,vi(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>v[i][j];
    }
    
    int result_dynamic = countSquares(v);
    cout << "Count_Square_Submatrices_with_All_Ones using Dynamic Programming: " << result_dynamic << endl;

    return 0;
}