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
    ll N, K;cin>>N>>K;
    vector<ll> G(N);
    vector<ll> A(N);
    rep(i, N) {
        cin>>G[i];
        G[i]--;
    }
    rep(i, N) {
        cin>>A[i];
    }
    struct info {
        ll d = -1;
        ll i = -1;
        ll j = -1;
    };
    vector<info> v(N, info());
    vector<vector<ll>> ring(N);
    auto dfs = [&] (ll i) {
        if (v[i].d != -1) return;
        ll id = 0;
        stack<ll> s;
        s.push(i);
        map<ll, ll> m;
        m[i] = id;
        id++;
        while (true) {
            ll now = s.top();
            ll next = G[now];
            if (m.find(next) != m.end()) {
                v[now].d = 0;
                v[now].i = next;
                v[now].j = id - m[next];
                ll ringid = id - m[next];
                ring[next] = vector<ll>(ringid + 1);
                ring[next][ringid] = now;
                ringid--;
                id--;
                s.pop();
                while (s.top() != next) {
                    ll now = s.top();s.pop();
                    v[now].d = 0;
                    v[now].i = next;
                    v[now].j = ringid;
                    ring[next][ringid] = now;
                    ringid--;
                    id--;
                }
                while(!s.empty()) {
                    ll now = s.top();s.pop();
                    v[now].d = id;
                    v[now].i = next;
                    v[now].j = 0;
                    id--;
                }
                return;
            }
            else {
                s.push(next);
                m[next] = id;
                id++;
            }
        }
    };
    rep(i, N) {
        dfs(i);
    }
    auto get_ans = [&] (ll x) {
        auto infom = v[x];
        ll d = infom.d;
        ll i = infom.i;
        ll j = infom.j;
        if (d < K) {
            while(d > 0) {
                x = G[x];
                d--;
            }
            return A[x];
        }
        else {
            ll p = (K - d) % ring[i].size();
            return A[ring[i][p]];
        }
    };
    rep (i, N) {
        out(get_ans(i));
    }

}
