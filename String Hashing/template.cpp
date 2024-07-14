#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vvvi vector<vector<vector<ll>>>
#define mll map<ll, ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define sz size()
#define f first
#define s second
#define nl endl
#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9
#define min_pq priority_queue<ll, vector<ll>, greater<ll>>
#define init(a,n) for(ll i=0; i<n; i++) { cin>>a[i]; }
#define print(a) for(const auto&i: (a)){cout<<i<<" ";}cout<<nl;
#define debug(a) for(const auto&i: (a)){cerr<<i<<" ";}cerr<<nl;

class HashedString {
private:
    static const ll M1 = 1e9 + 9;
    static const ll B1 = 9973;
    static const ll M2 = 1e9 + 7;
    static const ll B2 = 10007;

    static inline vll pow1 = {1};
    static inline vll pow2 = {1};
    vll p_hash1, p_hash2;

public:
    HashedString(const string &s) : p_hash1(s.length() + 1), p_hash2(s.length() + 1) {
        while (pow1.size() <= s.length()) {
            pow1.pb((pow1.back() * B1) % M1);
        }
        while (pow2.size() <= s.length()) {
            pow2.pb((pow2.back() * B2) % M2);
        }

        p_hash1[0] = 0;
        p_hash2[0] = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            p_hash1[i + 1] = ((p_hash1[i] * B1) % M1 + s[i]) % M1;
            p_hash2[i + 1] = ((p_hash2[i] * B2) % M2 + s[i]) % M2;
        }
    }

    pll get_hash(int start, int end) {
        if (start > end) return {0, 0};
        ll raw_val1 = (p_hash1[end + 1] - (p_hash1[start] * pow1[end - start + 1]) % M1 + M1) % M1;
        ll raw_val2 = (p_hash2[end + 1] - (p_hash2[start] * pow2[end - start + 1]) % M2 + M2) % M2;
        return {raw_val1, raw_val2};
    }

    static pll concatenate_hashes(const vector<pair<pll, ll>> &hashes) {
        ll combined_hash1 = 0, combined_hash2 = 0, cumulative_length = 0;
        for (const auto &[hash, length] : hashes) {
            auto [hash1, hash2] = hash;
            combined_hash1 = (combined_hash1 * pow1[length] % M1 + hash1) % M1;
            combined_hash2 = (combined_hash2 * pow2[length] % M2 + hash2) % M2;
            cumulative_length += length;

            while (pow1.size() <= cumulative_length) {
                pow1.pb((pow1.back() * B1) % M1);
            }
            while (pow2.size() <= cumulative_length) {
                pow2.pb((pow2.back() * B2) % M2);
            }
        }
        return {combined_hash1, combined_hash2};
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
 
    string s1(n, '1');
    string s2(n, '0');
 
    HashedString hs(s);
    HashedString hs1(s1);
    HashedString hs2(s2);
 
    set<pll> st;
 
    vll pre(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + (s[i - 1] == '0' ? 1 : 0);
    }
 
    while (m--) {
        ll l, r;
        cin >> l >> r;
        ll zeros = pre[r] - pre[l - 1];
        ll ones = (r - l + 1) - zeros;
        l--; r--;
 
        pll left_hash = (l > 0) ? hs.get_hash(0, l - 1) : pll{0, 0};
        pll zero_hash = (zeros > 0) ? hs2.get_hash(0, zeros - 1) : pll{0, 0};
        pll one_hash = (ones > 0) ? hs1.get_hash(0, ones - 1) : pll{0, 0};
        pll right_hash = (r < n - 1) ? hs.get_hash(r + 1, n - 1) : pll{0, 0};
 
        vector<pair<pll, ll>> v;
        if (l > 0) v.push_back({left_hash, l});
        if (zeros > 0) v.push_back({zero_hash, zeros});
        if (ones > 0) v.push_back({one_hash, ones});
        if (r < n - 1) v.push_back({right_hash, n - r - 1});
 
        pll p = HashedString::concatenate_hashes(v);
        st.insert(p);
    }
 
    cout << st.size() << nl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}