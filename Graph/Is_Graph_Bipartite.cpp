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

bool dfs(vvi &graph, int &i, vi &v, int c) {
    v[i] = c;
    for (int j = 0; j < graph[i].size(); j++) {
        if (v[graph[i][j]] == -1) {
            int t = (c == 1 ? 0 : 1);
            if (dfs(graph, graph[i][j], v, t)) return true;
        } else {
            if (v[graph[i][j]] == c) return true;
        }
    }
    return false;
}

bool bfs(vvi &graph, int &i, vi &v) {
    queue<int> q;
    q.push(i);
    v[i] = 0;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = 0; i < graph[t].size(); i++) {
            if (v[graph[t][i]] == -1) {
                v[graph[t][i]] = (v[t] == 1 ? 0 : 1);
                q.push(graph[t][i]);
            } else {
                if (v[graph[t][i]] == v[t]) return true;
            }
        }
    }
    return false;
}

bool isBipartite(vvi &graph) {
    int n = graph.size();
    vi v(n, -1);
    for (int i = 0; i < n; i++) {
        if (v[i] == -1) {
            if (bfs(graph, i, v)) return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    vvi v(n, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> v[i][j];
    }

    vvi graph(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(v[i][j]){
				graph[i].pb(j);
			}
		}
	}

    bool ans =isBipartite(graph);
    (ans ? (cout<<"true") : (cout<<"false"))<<nl;
    return 0;
}