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

vector<ll> divisor(ll N){
    vector<ll> ans;
    for(ll i=1;i*i<=N;i++){
        if(N%i==0){
            ans.push_back(i);
            if(i!=N/i){
                ans.push_back(N/i);
            }
        }
    }
    return ans;
}

int solve() {
    ll n;cin>>n;
    if(n == 0) return 1;
    auto v = divisor(n);
    sort(all(v));
    ll ans = INF;
    for(auto w:v) {
        if(w > 1e5 && w*w*w > n) break;
        for(auto d:v) {
            if(v > 1e8 && w*v > n) break;
            if(n/w % d == 0) {
                ll res = w + d + n/w/d;
                chmin(ans, res);
            }
        }
    }
    out(ans);
    return 0;
}

int main() {
    chrono::system_clock::time_point start, end;
    start = chrono::system_clock::now();
    while(!solve()) {}
    end = chrono::system_clock::now();
    double elapsed = chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cerr << "Elapsed time: " << elapsed << "ms" << endl;
}