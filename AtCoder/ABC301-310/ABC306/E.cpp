#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N, K, Q;cin>>N>>K>>Q;
    vector<ll> X(Q), Y(Q);
    rep(i, Q) cin>>X.at(i)>>Y.at(i), X.at(i)--;
    vector<ll> A(N, 0);
    multiset<ll> S, T;
    rep(i, K) S.insert(0);
    rep(i, N-K) T.insert(0);
    ll ans = 0;

    auto add = [&](ll x){
        S.insert(x); ans += x;
        ll y = *S.begin();
        S.erase(S.find(y)); ans -= y;
        T.insert(y);
    };
    auto del = [&](ll x){
        if(S.find(x) != S.end()){
            S.erase(S.find(x)); ans -= x;
            ll y = *T.rbegin();
            T.erase(T.find(y));
            S.insert(y); ans += y;
        }
        else{
            T.erase(T.find(x));
        }
    };

    rep(i, Q){
        add(Y.at(i));
        del(A.at(X.at(i)));
        A.at(X.at(i)) = Y.at(i);
        out(ans);
    }
}