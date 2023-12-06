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
    ll X;cin>>X;
    set<ll> s;
    for(ll k=1;k<=18;k++){
        for(ll f=1;f<=9;f++){
            for(ll d=-9;d<=9;d++){
                ll n = 0;
                ll digit = f;
                rep(i, k){
                    n *= 10;
                    n += digit;
                    if(i == k-1){
                        s.insert(n);
                        break;
                    }
                    digit += d;
                    if(digit >=10 || digit < 0) break;
                }
            }
        }
    }
    auto iter = s.lower_bound(X);
    out(*iter);
}