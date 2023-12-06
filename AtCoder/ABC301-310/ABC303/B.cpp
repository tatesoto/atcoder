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
    Graph G(M, vector<ll>(N));
    rep(i, M){
        rep(j, N){
            cin>>G.at(i).at(j);
            G.at(i).at(j)--;
        }
    }
    vector<vector<bool>> judge(N, vector<bool>(N, false));
    rep(i, N){
        judge.at(i).at(i) = true;
    }
    rep(i, M){
        rep(j, N-1){
            ll a = G.at(i).at(j);
            ll b = G.at(i).at(j+1);
            judge.at(a).at(b) = true;
            judge.at(b).at(a) = true;
        }
    }
    ll cnt = 0;
    rep(i, N){
        rep(j, N){
            if(!judge.at(i).at(j)) cnt++;
        }
    }
    out(cnt/2);
}