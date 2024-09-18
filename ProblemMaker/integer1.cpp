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
    auto pow = [&](ll x, ll n) {
        ll res = 1;
        while (n > 0) {
            if (n & 1) res = res * x;
            x = x * x;
            n >>= 1;
        }
        return res;
    }; 
    
    ll n = 100;
    vector<ll> a(n);
    iota(all(a), 1);
    vector<ll> prime;
    for(auto x : a) {
        if(x == 1) continue;
        bool ok = true;
        for(ll i = 2; i*i <= x; i++) {
            if(x % i == 0) {
                ok = false;
                break;
            }
        }
        if(ok) prime.push_back(x);
    }
    ofstream ofs("test.txt");
    vector<vector<vector<ll>>> ans(n+1, vector<vector<ll>>());
    for(auto p : a) {
        cout << p << '\n';
        ll x = p;
        vector<ll> v(4);
        vector<vector<ll>> tmp;
        auto dfs = [&] (auto dfs, ll i, ll sum) -> void {
            if(i == 4) {
                if(sum == x) {
                    tmp.push_back(v);
                }
                return;
            }
            for(auto j : prime) {
                if(sum + pow(j, i+1) > x) break;
                v[i] = j;
                dfs(dfs, i+1, sum + pow(j, i+1));
            }
        };
        dfs(dfs, 0, 0);
        ans[p] = tmp;
        if(ans[p].size() > 0) {
            ofs << p << " " << ans[p].size() << endl;
            rep(i, ans[p].size()) {
                rep(j, ans[p][i].size()) {
                    ofs << ans[p][i][j] << " ";
                }
                ofs << "\n";
            }
        }
    }
}