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
    Graph G(N);
    rep(i, M){
        ll a, b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<bool> white(N, false);
    ll K;cin>>K;
    vector<ll> p(K);
    vector<ll> d(K);
    rep(i, K) cin>>p.at(i)>>d.at(i), p.at(i)--;
    rep(i, K){
        set<ll> visited;
        queue<pair<ll,ll>> q;
        q.push({p.at(i), 0});
        visited.insert(p.at(i));
        while(!q.empty()){
            ll pos = q.front().first;
            ll dist = q.front().second;
            q.pop();
            if(dist < d.at(i)){
                white.at(pos) = true;
            }
            else if(dist == d.at(i)){
                continue;
            }
            for(auto next:G[pos]){
                if(visited.count(next)) continue;
                q.push({next, dist + 1});
                visited.insert(next);
            }
        }
    }
    rep(i, K){
        bool can_draw = false;
        set<ll> visited;
        queue<pair<ll,ll>> q;
        q.push({p.at(i), 0});
        visited.insert(p.at(i));
        while(!q.empty()){
            ll pos = q.front().first;
            ll dist = q.front().second;
            q.pop();
            if(dist == d.at(i)){
                if(!white.at(pos)){
                    can_draw = true;
                }
                continue;
            }
            for(auto next:G[pos]){
                if(visited.count(next)) continue;
                q.push({next, dist + 1});
                visited.insert(next);
            }
        }
        if(!can_draw){
            out("No");
            return 0;
        }
    }
    out("Yes");
    rep(i, N){
        if(white.at(i)) cout<<0;
        else cout<<1;
    }
    cout<<"\n";
}