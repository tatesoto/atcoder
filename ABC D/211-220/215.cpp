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

//素因数分解
map<ll,ll> prime_factor(ll N){
    map<ll,ll> ans;
    for(ll i=2;i*i<=N;i++){
        while(N%i==0){
            ans[i]++;
            N/=i;
        }
    }
    if(N!=1){
        ans[N]=1;
    }
    return ans;
}

int main() {
    ll N,M;cin>>N>>M;
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    vector<bool> b(M+1,true);
    b.at(0)=false;
    rep(i,N){
        map<ll,ll> prime=prime_factor(a.at(i));
        for(auto x:prime){
            ll p=x.first;
            if(p>M||!b.at(p)) continue;
            for(ll j=p;j<=M;j+=p){
                b.at(j)=false;
            }
        }
    }
    vector<ll> ans;
    rep(i,M+1){
        if(b.at(i)){
            ans.push_back(i);
        }
    }
    out(ans.size());
    for(auto x:ans){
        out(x);
    }
}