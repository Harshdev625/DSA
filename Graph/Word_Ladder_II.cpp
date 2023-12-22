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


vector<vector<string>> findLadders(string start, string end, vector<string>& wordList) {
    unordered_set<string>s(wordList.begin(),wordList.end());
    queue<vector<string>>q;
    q.push({start});
    int lvl=0;
    v.pb(start);
    vector<vector<string>>ans;
    vector<string>v;
    while(!q.empty()){
        vector<string>vec=q.front();
        q.pop();
        if(vec.size()>lvl){
            lvl++;
            for(int i=0;i<v.size();i++){
                s.erase(v[i]);
            }
        }
        string word=vec.back();
        if(word==end){
            if(ans.size()==0){
                ans.pb(vec);
            }
            else if(ans[0].size()==vec.size()){
                ans.pb(vec);
            }
        }
        for(int i=0;i<word.size();i++){
            char prev=word[i];
            for(char j='a';j<='z';j++){
                word[i]=j;
                if(s.find(word)!=s.end()){
                    vec.pb(word);
                    q.push(vec);
                    v.pb(word);
                    vec.pop_back();
                }
            }
            word[i]=prev;
        }
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
