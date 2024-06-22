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
    ll N;cin>>N;
    vector<pair<pair<ll,ll>, ll>> card(N);
    rep(i, N) {
        ll a, c;cin>>a>>c;
        card[i] = {{a, c}, i+1};
    }
    sort(all(card));
    reverse(all(card));
    ll nowMinC = INF;
    vector<ll> ans;
    rep(i, N){
        if(card[i].first.second > nowMinC) continue;
        chmin(nowMinC, card[i].first.second);
        ans.push_back(card[i].second);
    }
    sort(all(ans));
    out(ans.size());
    for(auto x: ans) {
        cout << x << (x == ans.back() ? '\n' : ' ');
    }
}