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

int largestRectangleArea(vector < int > & heights) {
    int n = heights.size();
    vector < int > rightsmall(n);
    vector < int > leftsmall(n);
    stack < int > s;
    for (int i = 0; i < heights.size(); i++) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        if (s.empty()) {
            leftsmall[i] = 0;
        } else {
            leftsmall[i] = s.top() + 1;
        }
        s.push(i);
    }
    while (s.size()) s.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        if (s.empty()) {
            rightsmall[i] = n;
        } else {
            rightsmall[i] = s.top();
        }
        s.push(i);
    }
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, heights[i] * (rightsmall[i] - leftsmall[i]));
    }
    return maxi;
}

int maximalAreaOfSubMatrixOfAll1(vector < vector < int >> & matrix, int n, int m) {
    int maxi = largestRectangleArea(matrix[0]);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j]) matrix[i][j] += matrix[i - 1][j];
        }
        maxi = max(maxi, largestRectangleArea(matrix[i]));
    }
    return maxi;
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
    
    int result_dynamic = maximalAreaOfSubMatrixOfAll1(v,n,m);
    cout << "Maximal_Rectangle using Dynamic Programming: " << result_dynamic << endl;

    return 0;
}