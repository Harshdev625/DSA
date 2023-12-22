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

int ladderLength(string start, string end, vector<string>& wordList) {
    unordered_set<string>s(wordList.begin(),wordList.end());
    queue<pair<string,int>>q;
    q.push({start,1});
    s.erase(start);
    while(!q.empty()){
        string word=q.front().f;
        int step=q.front().s;
        q.pop();
        if(word==end)return step;
        for(int i=0;i<word.size();i++){
            char prev =word[i];
            for(char j='a';j<='z';j++){
                word[i]=j;
                if(s.find(word)!=s.end()){
                    s.erase(word);
                    q.push({word,step+1});
                }
            }
            word[i]=prev;
        }
    }
    return 0;
}

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	string start,end;
    int n;
    cin>>n;
    cin>>start;
    cin>>end;

    vector<string>wordList;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        wordList.pb(s);
    }
    int ans=ladderLength(start,end,wordList);
    cout<<ans<<nl;
	return 0;
}
