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
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

int main() {
    ll N, M;cin>>N>>M;
    vector<vector<ll>> G(N, vector<ll>(N, -1));
    rep(i, M){
        ll A, B, C;cin>>A>>B>>C;
        A--; B--;
        G[A][B] = C;
        G[B][A] = C;
    }
    ll ans = -1;
    vector<ll> v(N);
    rep(i, N) v[i] = i;
    do{
        ll sum = 0;
        rep(i, N){
            if(i == N-1) break;
            ll from = v[i];
            ll to = v[i+1];
            if(G[from][to] == -1){
                break;
            }
            sum += G[from][to];
        }
        chmax(ans, sum);
    }while(next_permutation(all(v)));
    out(ans);
}
