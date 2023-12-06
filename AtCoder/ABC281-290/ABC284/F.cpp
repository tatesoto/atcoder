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

//x^NをMODで割ったあまり
ll MOD=(1LL<<30);
ll mod_pow(ll x,ll N){
    ll ans=1;
    while(N>0){
        if(N & 1){
            ans=ans*x%MOD;
        }
        x=x*x%MOD;
        N>>=1;
    }
    return ans;
}
vector<ll> power100;

int main() {
    ll N;cin>>N;
    string T;cin>>T;
    power100.resize(N,1);
    for(ll i=1;i<N;i++){
        power100.at(i)=power100.at(i-1)*100%MOD;
    }
    string S1,S2;
    S1=T.substr(0,N);
    S2=T.substr(N,N);
    ll hash1=0;
    ll hash2=0;
    rep(i,N){
        hash1*=100;
        hash1+=S1.at(i)-'0';
        hash1%=MOD;
    }
    rep(i,N){
        hash2*=100;
        hash2+=S2.at(N-1-i)-'0';
        hash2%=MOD;
    }
    ll ans=-1;
    rep(i,N){
        if(hash1==hash2){
            ans=i;
            break;
        }
        hash1-=(T.at(i)-'0')*power100.at(N-1);
        hash1*=100;
        hash1+=T.at(i+N)-'0';
        hash1=(hash1+2*MOD)%MOD;
        hash2-=(T.at(i+N)-'0')*power100.at(i);
        hash2+=(T.at(i)-'0')*power100.at(i);
        hash2=(hash2+2*MOD)%MOD;
    }
    string S;
    rep(i,2*N){
        if(i<ans or ans+N<=i){
            S.push_back(T.at(i));
        }
    }
    if(ans!=-1){
        out(S);
    }
    out(ans);
}