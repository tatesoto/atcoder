#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

int main() {
    auto encoder = [&](string s) -> ll {
        ll res = 0;
        for(char c : s) {
            res *= 26;
            res += c - 'a' + 1;
        }
        return res;
    };
    
    auto decoder = [&](ll n) -> string {
        string res;
        while(n > 0) {
            n--;
            res += 'a' + n % 26;
            n /= 26;
        }
        reverse(all(res));
        return res;
    };

    ll K;cin>>K;
    vector<string> S(K);
    rep(i,K) cin>>S[i];
    ll Q;cin>>Q;
    vector<pair<ll,ll>> N(Q);
    rep(i,Q) {
        ll n;cin>>n;
        N[i] = {n, i};
    }

    vector<ll> words;
    words.push_back(0);
    rep(i,K) {
        if(S[i].size() > 13 || S[i] >= "txwotpzthebsb") continue;
        words.push_back(encoder(S[i]));
    }
    sort(all(words));
    sort(all(N));
    words.push_back(2e18);
    vector<string> ans(Q);
    ll id = 0;
    ll now = 0;
    rep(i, words.size()) {
        ll next = words[i]-i+1;
        while(id < Q && N[id].first < next) {
            ans[N[id].second] = decoder(N[id].first + i - 1);
            id++;
        }
        now = next;
    }
    rep(i,Q) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
