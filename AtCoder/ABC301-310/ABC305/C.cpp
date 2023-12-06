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
    ll H,W;cin>>H>>W;
    vector<string> S(H);
    rep(i, H) cin>>S.at(i);
    vector<ll> dx = {0, 1, 0, -1};
    vector<ll> dy = {1, 0, -1, 0};
    rep(i, H){
        rep(j, W){
            if(S.at(i).at(j) == '#') continue;
            ll cnt = 0;
            rep(dir, 4){
                ll nx = i + dx.at(dir);
                ll ny = j + dy.at(dir);
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(S.at(nx).at(ny) == '#') cnt++;
            }
            if(cnt >= 2){
                cout<<i+1<<" "<<j+1<<"\n";
                return 0;
            }
        }
    }
}