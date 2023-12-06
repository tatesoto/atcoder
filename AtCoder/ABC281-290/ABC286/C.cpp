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

ll N;
ll bcnt(string S){
    ll cnt = 0;
    rep(i,N){
        ll j = N-1-i;
        if(i >= j){
            break;
        }
        if(S.at(i)!=S.at(j)){
            cnt++;
        }
    }
    return cnt;
}


int main() {
    ll A,B;cin>>N>>A>>B;
    string S;cin>>S;
    ll ans = INF;
    rep(i,N){
        ll rec = i*A;
        rec += bcnt(S)*B;
        chmin(ans , rec);
        char c = S.at(0);
        S = S.substr(1,N-1);
        S.push_back(c);
    }
    out(ans);
}