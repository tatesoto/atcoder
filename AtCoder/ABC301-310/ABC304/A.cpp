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
    ll N;cin>>N;
    vector<string> S(N);
    vector<ll> a(N);
    rep(i, N) cin>>S.at(i)>>a.at(i);
    ll min_age = INF;
    rep(i, N){
        chmin(min_age, a.at(i));
    }
    rep(i, N){
        if(a.at(i) == min_age){
            ll cnt = 0;
            for(int j = i;;j++){
                out(S.at(j%N));
                cnt++;
                if(cnt == N) return 0;
            }

        }
    }
}