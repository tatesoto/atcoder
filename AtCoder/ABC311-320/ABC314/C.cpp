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
    ll N,M;cin>>N>>M;
    string S;cin>>S;
    vector<ll> C(N);
    vector<vector<ll>> color(M);
    vector<ll> color_id(M, 0);
    rep(i, N){
        ll c;cin>>c;c--;
        color.at(c).push_back(i);
        C.at(i) = c;
    }
    string ans;
    rep(i, N){
        ll c = C.at(i);
        ll m = color.at(c).size();
        ans.push_back(S.at(color.at(c).at((color_id.at(c)+m-1)%m)));
        color_id.at(c)++;
    }
    out(ans);
}
