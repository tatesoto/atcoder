#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<endl
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
    vector<vector<ll>> a(N, vector<ll>(N)), b(N, vector<ll>(N)), c;
    rep(i, N){
        rep(j, N){
            cin>>a.at(i).at(j);
        }
    }
    rep(i, N){
        rep(j, N){
            cin>>b.at(i).at(j);
        }
    }
    c = a;
    rep(rot, 4){
        rep(i, N){
            rep(j, N){
                a.at(i).at(j) = c.at(N-j-1).at(i);
            }
        }
        bool judge = true;
        rep(i, N){
            bool bre = false;
            rep(j, N){
                if(a.at(i).at(j) == 1){
                    if(b.at(i).at(j) != 1){
                        judge = false;
                        bre = true;
                        break;
                    }
                }
            }
            if(bre) break;
        }
        if(judge){
            out("Yes");
            return 0;
        }
        c = a;
    }
    out("No");
}