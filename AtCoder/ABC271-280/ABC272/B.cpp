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
    ll N,M;cin>>N>>M;
    vector<vector<bool>> judge(N+1,vector<bool>(N+1,false));
    for(ll i=0;i<=N;i++){
        judge.at(i).at(i)=true;
    }
    rep(i,M){
        ll k;cin>>k;
        vector<ll> sanka;
        rep(i,k){
            ll x;cin>>x;
            sanka.push_back(x);
        }
        rep(i,sanka.size()){
            for(ll j=i+1;j<sanka.size();j++){
                ll a=sanka.at(i);
                ll b=sanka.at(j);
                judge.at(a).at(b)=true;
                judge.at(b).at(a)=true;
            }
        }
    }
    for(ll i=1;i<=N;i++){
        for(ll j=1;j<=N;j++){
            if(!judge.at(i).at(j)){
                out("No");
                return 0;
            }
        }
    }
    out("Yes");
}