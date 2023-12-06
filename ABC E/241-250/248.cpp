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
    ll N,K;cin>>N>>K;
    vector<pair<ll, ll>> xy(N);
    rep(i, N) cin>>xy.at(i).first>>xy.at(i).second;
    if(K == 1){
        out("Infinity");
        return 0;
    }
    ll ans = 0;
    vector<vector<bool>> check(N, vector<bool>(N, false));
    rep(i, N) check[i][i] = true;
    rep(i, N){
        for(ll j=i+1;j<N;j++){
            if(check[i][j]) continue;
            ll x1 = xy.at(i).first;
            ll y1 = xy.at(i).second;
            ll x2 = xy.at(j).first;
            ll y2 = xy.at(j).second;
            check[i][j] = true;
            check[j][i] = true; 
            ll cnt = 0;
            vector<ll> same_line;
            same_line.push_back(i);
            same_line.push_back(j);
            rep(k, N){
                ll x3 = xy.at(k).first;
                ll y3 = xy.at(k).second;
                ll judge = (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
                if(judge == 0){
                    same_line.push_back(k);
                    cnt++;
                }
            }
            rep(k, same_line.size()){
                rep(l, same_line.size()){
                    ll x = same_line.at(k);
                    ll y = same_line.at(l);
                    check[x][y] = true;
                }
            }
            if(cnt >= K) ans++;
        }   
    }
    out(ans);
}