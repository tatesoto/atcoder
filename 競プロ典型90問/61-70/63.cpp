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
    Graph G(H,vector<ll>(W));
    rep(i,H){
        rep(j,W){
            cin>>G.at(i).at(j);
        }
    }
    ll ans=0;
    for(ll bit=1;bit<(1<<H);bit++){
        vector<ll> erase;
        for(ll i=0;i<H;i++){
            if(bit & (1<<i)){
                erase.push_back(i);
            }
        }
        map<ll,ll> mp;
        for(ll j=0;j<W;j++){
            bool same=true;
            ll now=G.at(erase.at(0)).at(j);
            for(ll k=0;k<erase.size();k++){
                if(G.at(erase.at(k)).at(j)!=now){
                    same=false;
                    break;
                }
                now=G.at(erase.at(k)).at(j);
            }    
            if(same){
                mp[now]++;
            }
        }
        ll cnt=0;
        for(auto p:mp){
            chmax(cnt,p.second);
        }
        chmax(ans,(ll)(cnt*erase.size()));
    }
    out(ans);
}