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
    vector<string> S(H),T(H);
    rep(i,H){
        cin>>S.at(i);
    }
    rep(i,H){
        cin>>T.at(i);
    }
    vector<string> nS(W),nT(W);
    rep(i,H){
        rep(j,W){
            nS.at(j).push_back(S.at(i).at(j));
            nT.at(j).push_back(T.at(i).at(j));
        }
    }
    map<string,ll> Smp,Tmp;
    rep(i,W){
        Smp[nS.at(i)]++;
        Tmp[nT.at(i)]++;
    }
    for(auto p:Smp){
        if(Tmp[p.first]!=p.second){
            out("No");
            return 0;
        }
    }
    out("Yes");
}