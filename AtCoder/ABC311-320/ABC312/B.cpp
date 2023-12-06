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
    rep(i, N){
        rep(j, M){
            if(i + 8 >= N || j + 8 >= M){
                continue;
            }
            bool judge = true;
            rep(k, 9){
                rep(l, 9){
                    if(0 <= k && k <= 2){
                        if(0 <= l && l <= 2 && S[i+k][j+l] == '.') judge = false;
                        if(l == 3 && S[i+k][j+l] == '#') judge = false;
                    }
                    else if(k == 3){
                        if(0 <= l && l <= 3 && S[i+k][j+l] == '#') judge = false; 
                    }
                    if(6 <= k && k <= 8){
                        if(6 <= l && l <= 8 && S[i+k][j+l] == '.') judge = false;
                        if(l == 5 && S[i+k][j+l] == '#') judge = false;
                    }
                    else if(k == 5){
                        if(5 <= l && l <= 8 && S[i+k][j+l] == '#') judge = false; 
                    }
                }
            }
            if(judge){
                cout<<i+1<<" "<<j+1<<"\n";
            }
        }
    }
}