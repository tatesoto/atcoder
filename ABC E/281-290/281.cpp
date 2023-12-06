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
    ll N,M,K;cin>>N>>M>>K;
    vector<ll> A(N);
    rep(i, N) cin>>A.at(i);
    multiset<ll> s,t;
    vector<ll> tmp(M);
    rep(i, M) tmp.at(i) = A.at(i);
    sort(all(tmp));
    ll ans = 0;
    rep(i, M){
        if(i < K){
            ans += tmp.at(i);
            s.insert(tmp.at(i));
        }
        else{
            t.insert(tmp.at(i));
        }
    }
    out(ans);
    for(ll i=M;i<N;i++){
        if(t.count(A.at(i-M))){
            t.erase(t.find(A.at(i-M)));
            auto iter = s.rbegin();
            ll sM = *iter;
            if(A.at(i) >= sM){
                t.insert(A.at(i));
                out(ans);
            }
            else{
                s.erase(s.find(sM));
                t.insert(sM);
                s.insert(A.at(i));
                ans = ans - sM + A.at(i);
                out(ans);
            }
        }
        else{
            s.erase(s.find(A.at(i-M)));
            if(t.size() == 0){
                s.insert(A.at(i));
                ans = ans - A.at(i-M) + A.at(i);
                out(ans);
                continue;
            }
            auto iter = t.begin();
            ll tm = *iter;
            if(A.at(i) <= tm){
                s.insert(A.at(i));
                ans = ans - A.at(i-M) + A.at(i);
                out(ans);
            }
            else{
                t.erase(iter);
                s.insert(tm);
                t.insert(A.at(i));
                ans = ans - A.at(i-M) + tm;
                out(ans);
            }
        }
    }
}