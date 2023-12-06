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
    rep(i, N) cin>>S.at(i);
    rep(i, N){
        rep(j, N){
            if(i == j) continue;
            string T = S.at(i) + S.at(j);
            bool judge = true;
            rep(k, T.size()){
                if(k > T.size() - 1 - k) break;
                if(T.at(k) != T.at(T.size() - 1 - k)) judge = false;
            }
            if(judge){
                out("Yes");
                return 0;
            }
        }
    }
    out("No");
}