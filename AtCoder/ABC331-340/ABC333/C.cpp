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
    set<ll> st;
    vector<ll> a;
    ll res = 0;
    rep(i, 12){
        res *= 10;
        res += 1;
        a.push_back(res);
    }
    rep(i, 12){
        rep(j, 12){
            rep(k, 12){
                st.insert(a[i] + a[j] + a[k]);
            }
        }
    }
    ll cnt = 0;
    for(auto x: st){
        if(cnt == N-1){
            out(x);
            return 0;
        }
        cnt++;
    }
}