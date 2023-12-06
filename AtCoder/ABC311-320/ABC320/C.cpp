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
    ll M;cin>>M;
    vector<string> S(3);
    rep(i, 3) cin>>S[i];
    vector<set<ll>> st(3);
    rep(i, 3){
        rep(j, M){
            st[i].insert(S[i][j] - '0');
        }
    }
    vector<ll> perm = {0, 1, 2};
    ll ans = INF;
    do{
        for(int num = 0; num <= 9; num++){
            ll t = -1;
            for(auto i:perm){
                if(!st[i].count(num)){
                    t = INF;
                    break;
                }
                while(1){
                    t++;
                    if(S[i][t%M] - '0' == num) break;
                }
            }
            chmin(ans, t);
        }

    }while(next_permutation(all(perm)));
    if(ans == INF) out(-1);else out(ans);
}
