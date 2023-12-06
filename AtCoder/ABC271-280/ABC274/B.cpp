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

int main() {
    ll H,W;cin>>H>>W;
    vector<vector<char>> c(H,vector<char>(W));
    rep(i,H){
        rep(j,W){
            cin>>c.at(i).at(j);
        }
    }
    rep(j,W){
        ll cnt=0;
        rep(i,H){
            if(c.at(i).at(j)=='#'){
                cnt++;
            }
        }
        cout<<cnt;
        if(j<W-1){
            cout<<" ";
        }
    }
    cout<<endl;
}