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
    ll N;cin>>N;
    string T;cin>>T;
    vector<string> S(N);
    rep(i, N) cin>>S[i];
    ll n = T.size();
    vector<ll> ans;
    rep(i, N){
        ll m = S[i].size();
        bool judge = true;
        if(m == n){
            ll cnt = 0;
            rep(j, m){
                if(S[i][j] != T[j]) cnt++;
            }
            if(cnt <= 1) ans.push_back(i+1);
        }
        else if(m == n-1){
            ll d = 0;
            rep(j, n){
                if(d == 0 && j == n-1) break;
                if(S[i][j-d] != T[j]) d++;
                if(d >= 2){
                    judge = false;
                    break;
                }
            }
            if(judge) ans.push_back(i+1);
        }
        else if(m == n+1){
            ll d = 0;
            rep(j, m){
                if(d == 0 && j == m-1) break;
                if(S[i][j] != T[j-d]) d++;
                if(d >= 2){
                    judge = false;
                    break;
                }
            }
            if(judge) ans.push_back(i+1);
        }
    }
    out(ans.size());
    for(auto s:ans) out(s);
}