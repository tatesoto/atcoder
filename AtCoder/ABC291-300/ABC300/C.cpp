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
    vector<vector<char>> C(H+2, vector<char>(W+2, '.'));
    rep(i, H){
        rep(j, W){
            cin>>C.at(i+1).at(j+1);
        }
    }
    const vector<ll> dx = {1, 1, -1, -1};
    const vector<ll> dy = {1, -1, 1, -1};
    vector<ll> ans(min(H, W)+1, 0);
    rep(i, H+1){
        rep(j, W+1){
            if(C.at(i).at(j) == '.') continue;
            ll n = INF;
            rep(dir, 4){
                ll cnt = -1;
                ll nx = i;
                ll ny = j;
                while(C.at(nx).at(ny) == '#'){
                    nx += dx.at(dir);
                    ny += dy.at(dir);
                    cnt++;
                }
                chmin(n, cnt);
            }
            ans.at(n)++;
        }
    }
    rep(i, min(H, W)){
        cout<<ans.at(i+1);
        if(i != min(H, W) + 1) cout<<" ";
    }
    cout<<endl;
}