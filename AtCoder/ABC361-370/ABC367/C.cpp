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
    ll N, K; cin>>N>>K;
    vector<ll> R(N);
    rep(i, N) cin>>R[i];
    auto dfs = [&] (auto dfs, ll i, vector<ll> &v) -> void {
        if (i == N) {
            ll sum = 0;
            rep(i, N) sum += v[i];
            if (sum % K == 0) {
                for (int i = 0; i < int(v.size()); i++) {
                    cout << v[i] << " ";
                    if(i == int(v.size()) - 1) cout << endl;
                }
            }
            return;
        }
        for (int j = 1; j <= R[i]; j++) {
            v.push_back(j);
            dfs(dfs, i + 1, v);
            v.pop_back();
        }
        return;
    };
    vector<ll> v;
    dfs(dfs, 0, v);
}
