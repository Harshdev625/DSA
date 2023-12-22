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

unordered_map<string,int>m;
vector<vector<string>>ans;
string start;
int n;

void dfs(string word, vector<string>& seq) {
    if (word == start) {
        reverse(seq.begin(), seq.end());
        ans.pb(seq);
        reverse(seq.begin(), seq.end());
        return;
    }
    int step = m[word];
    for (int i = 0; i < n; i++) {
        char prev = word[i];
        for (char j = 'a'; j <= 'z'; j++) {
            word[i] = j;
            if (m.find(word) != m.end() && m[word] + 1 == step) {
                seq.pb(word);
                dfs(word, seq);
                seq.pop_back();
            }
        }
        word[i] = prev;
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> s(wordList.begin(), wordList.end());
    queue<string> q;
    q.push(beginWord);
    m[beginWord] = 1;
    start = beginWord;
    s.erase(beginWord);
    n = beginWord.size();
    while (!q.empty()) {
        string word = q.front();
        int step = m[word];
        q.pop();
        if (word == endWord) break;
        for (int i = 0; i < n; i++) {
            char prev = word[i];
            for (char j = 'a'; j <= 'z'; j++) {
                word[i] = j;
                if (s.find(word) != s.end()) {
                    q.push(word);
                    s.erase(word);
                    m[word] = step + 1;
                }
            }
            word[i] = prev;
        }
    }
    if (m.find(endWord) != m.end()) {
        vector<string> seq;
        seq.pb(endWord);
        dfs(endWord, seq);
    }
    return ans;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	string start,end;
    int n;
    cin>>start;
    cin>>end;
    cin>>n;

    vector<string>wordList;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        wordList.pb(s);
    }
    vector<vector<string>> ans=findLadders(start,end,wordList);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<nl;
    }
	return 0;
}
