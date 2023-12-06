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
    int H, W;cin>>H>>W;
    vector<char> G(H*W);
    rep(i, H*W) cin>>G.at(i);
    auto move = [&](int pos, int dir){
        vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
        int i = pos/W, j = pos%W;
        int ni = i + dx.at(dir), nj = j + dy.at(dir);
        if(ni < 0 || ni >= H || nj < 0 || nj >= W) return 100;
        return ni*W + nj;  
    };
    ll ans = -1;
    rep(s, H*W){
        if(G.at(s) == '#') continue;
        stack<vector<ll>> q;
        q.push({0, s, 0});
        ll max_cnt = 0;
        while(!q.empty()){
            auto p = q.top();q.pop();
            ll cnt = p.at(0), pos = p.at(1), S = p.at(2);
            rep(dir, 4){
                int next = move(pos, dir);
                if(next < 0 || next >= H*W) continue;
                if(G.at(next) == '#') continue;
                if(S>>next & 1) continue;
                if(next == s) chmax(max_cnt, cnt+1);
                else{
                    S = S | 1<<next;
                    q.push({cnt+1, next, S});

                }
            }
        }
        if(max_cnt > 2) chmax(ans, max_cnt);
    }
    out(ans);
}