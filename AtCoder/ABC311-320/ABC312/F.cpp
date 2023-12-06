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
    ll N, M;cin>>N>>M;
    vector<ll> A, B, C;
    rep(i, N){
        ll t, x;cin>>t>>x;
        if(t == 0) A.push_back(x);
        else if(t == 1) B.push_back(x);
        else C.push_back(x);
    }
    sort(all(A), greater<ll>());
    sort(all(B), greater<ll>());
    sort(all(C), greater<ll>());
    vector<ll> cutter(N+1, 0);
    ll now = 0;
    rep(i, C.size()){
        ll next = C.at(i);
        while(next > 0){
            now++;
            if(now == N+1){
                break;
            }
            cutter.at(now) = i+1;
            next--;
        }
        if(now == N+1){
            break;
        }
    }
    vector<ll> sa, sb;
    sa.push_back(0);
    rep(i, A.size()){
        sa.push_back(sa.back() + A.at(i));
    }
    sb.push_back(0);
    rep(i, B.size()){
        sb.push_back(sb.back() + B.at(i));
    }
    ll ans = -1;
    rep(k, M+1){
        ll res = 0;
        ll need = cutter.at(k);
        if(M-k-need < A.size()){
            res += sa.at(max(M-k-need, 0LL));
        }
        else{
            res += sa.at(A.size());
        }
        res += sb.at(min(k, int(B.size())));
        chmax(ans, res);
    }
    out(ans);
}