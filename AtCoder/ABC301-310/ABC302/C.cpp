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
    vector<string> S(N);
    rep(i, N) cin>>S.at(i);
    sort(all(S));
    bool judge = false;
    do
    {   
        bool jd = true;
        rep(i, N-1){
            ll cnt = 0;
            rep(j, M){
                if(S.at(i).at(j) != S.at(i+1).at(j)) cnt++;
            }
            if(cnt != 1){
                jd = false;
            }
        }
        if(jd){
            judge = true;
        }
    } while (next_permutation(all(S)));
    if(judge) out("Yes");
    else out("No");
}