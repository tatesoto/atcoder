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

int main() {
    ll N,M,H,K;cin>>N>>M>>H>>K;
    string S;cin>>S;
    vector<ll> dx = {1, -1, 0, 0};
    vector<ll> dy = {0, 0, 1, -1};
    map<char,ll> direction = {{'R', 0}, {'L', 1}, {'U', 2}, {'D', 3}};
    set<pair<ll,ll>> item;
    rep(i, M){
        ll x,y;cin>>x>>y;
        item.insert({x, y});
    }
    ll nx = 0;
    ll ny = 0;
    rep(i, N){
        char c = S.at(i);
        ll dir = direction[c];
        nx += dx.at(dir);
        ny += dy.at(dir);
        H--;
        if(H < 0){
            out("No");
            return 0;
        }
        if(item.count({nx, ny})){
            if(chmax(H, K)){
                item.erase({nx, ny});
            }
        }
    }
    out("Yes");
}