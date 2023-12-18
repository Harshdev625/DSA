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

string getAlienLanguage(vector<string> &graph, int k){

    vvi v(k,vi(26,0));
	int n=graph.size();
	vi indegree(k);
	for(int i=1; i<n; i++){
		int len1 = graph[i-1].size();
		int len2 = graph[i].size();
		for(int j=0, k=0; j<len1 && k<len2; j++, k++){
			if(graph[i-1][j] != graph[i][k]){
				if(!v[graph[i-1][j]-'a'][graph[i][k]-'a']){
					v[graph[i-1][j]-'a'][graph[i][k]-'a'] = 1;
					indegree[graph[i][k]-'a']++;
					break;
				}
				else break;
			}
		}
	}

	queue<int>q;
	for(int i=0;i<k;i++){
		if(!indegree[i]){
			q.push(i);
		}
	}

	string ans;
	while(!q.empty()){
		int t=q.front();
		ans.pb('a'+t);
		q.pop();
		for(int i=0;i<26;i++){
			if(v[t][i]){
				indegree[i]--;
				if(!indegree[i])q.push(i);
			}
		}
	}
	return ans;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	int m,n;
	cin>>m>>n;
	vector<string>v;
	string s;
	for(int i=0;i<m;i++){
		cin>>s;
		v.pb(s);
	}
	string ans=getAlienLanguage(v,n);
	cout<<ans<<nl;
	return 0;
}
