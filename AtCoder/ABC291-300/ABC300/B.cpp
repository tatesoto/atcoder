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
    ll H,W;cin>>H>>W;
    vector<string> A(H),B(H);
    rep(i, H) cin>>A.at(i);
    rep(i, H) cin>>B.at(i);
    rep(k, H){
        rep(l, W){
            vector<string> tmp = A;
            rep(i, H){
                rep(j, W){
                    tmp.at(i).at(j) = A.at((i+k)%H).at((j+l)%W);
                }
            }
            bool judge = true;
            rep(i, H){
                if(tmp.at(i) != B.at(i)) judge = false;
            }
            if(judge){
                out("Yes");
                return 0;
            }
        }
    }
    out("No");
}