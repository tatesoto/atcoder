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
    ll N;cin>>N;
    ll Q;cin>>Q;
    vector<ll> player(N, 0);
    rep(i, Q){
        ll c;cin>>c;
        ll x;cin>>x;
        x--;
        if(c == 1){
            player.at(x)++;
        }
        else if(c == 2){
            player.at(x)+=2;
        }
        else{
            if(player.at(x) >= 2){
                out("Yes");
            }
            else{
                out("No");
            }
        }
    }
}