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
    ll N,P,Q;cin>>N>>P>>Q;
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    ll cnt=0;
    for(ll i=0;i<N-4;i++){
        for(ll j=i+1;j<N-3;j++){
            for(ll k=j+1;k<N-2;k++){
                for(ll l=k+1;l<N-1;l++){
                    for(ll m=l+1;m<N;m++){
                        ll b=1;
                        b*=a.at(i);
                        b%=P;
                        b*=a.at(j);
                        b%=P;
                        b*=a.at(k);
                        b%=P;
                        b*=a.at(l);
                        b%=P;
                        b*=a.at(m);
                        b%=P;
                        if(b==Q){
                            cnt++;
                        }
                    }
                }
            }
        }
    }
    out(cnt);
}