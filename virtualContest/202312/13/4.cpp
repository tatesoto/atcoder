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
    ll N, X, Y;
    cin >> N >> X >> Y;
    X--;Y--;
    Graph G(N);
    rep(i, N - 1) {
        ll a, b;cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);        
    }

    vector<ll> prev(N, -1);
    vector<bool> visited(N, false);
    stack<ll> st;
    st.push(X);
    while(!st.empty()) {
        ll v = st.top();st.pop();
        visited[v] = true;
        for(auto nv : G[v]) {
            if(visited[nv]) continue;
            prev[nv] = v;
            st.push(nv);
        }
    }
    
    vector<ll> path;
    ll now = Y;
    while(now != -1) {
        path.push_back(now);
        now = prev[now];
    }
    reverse(all(path));
    for(auto v : path) {
        out(v + 1);
    }

}
