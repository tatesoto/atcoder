#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll H,W;cin>>H>>W;
    vector<string> S(H);
    rep(i, H){
        cin>>S.at(i);
    }
    rep(i, H){
        rep(j, W){
            if(j == W-1) continue;
            if(S.at(i).at(j) == 'T' && S.at(i).at(j+1) == 'T'){
                S.at(i).at(j) = 'P';
                S.at(i).at(j+1) = 'C';
            }
        }
    }
    rep(i,H){
        out(S.at(i));
    }
}