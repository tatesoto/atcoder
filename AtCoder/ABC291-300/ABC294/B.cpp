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
    vector<string> G(H);
    rep(i, H){
        rep(j, W){
            ll c;cin>>c;
            if(c == 0){
                G.at(i).push_back('.');
            }
            else{
                c--;
                G.at(i).push_back('A' + c);
            }
        }
    }
    for(auto &s:G){
        out(s);
    }
}