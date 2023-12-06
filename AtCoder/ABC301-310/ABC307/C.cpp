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
    vector<vector<string>> G(3);
    auto input = [&](int i){
        ll h, w;cin>>h>>w;
        rep(_, h){
            string s;cin>>s;
            G[i].push_back(s);
        }
    };
    rep(i, 3) input(i);

    auto put = [&](int i, int x, int y, vector<vector<bool>>& exist){
        rep(h, G[i].size()){
            rep(w, G[i][0].size()){
                int nh = x + h;
                int nw = y + w;
                if(G[i][h][w] == '#') exist[nh][nw] = true;
            }
        }
    };

    auto check = [&](vector<vector<bool>> exist){
        ll cnt = 0;
        rep(h, G[2].size()){
            rep(w, G[2][0].size()){
                int i = 9 + h;
                int j = 9 + w;
                if((exist[i][j] && G[2][h][w] == '.') || (!exist[i][j] && G[2][h][w] == '#')) return false;
                if(exist[i][j]) cnt++;
            }
        }
        rep(i, 30){
            rep(j, 30){
                if(exist[i][j]) cnt--;
            }
        }
        if(cnt != 0) return false;
        return true;
    };
    
    rep(x1, 20){
        rep(y1, 20){
            rep(x2, 20){
                rep(y2, 20){
                    vector<vector<bool>> exist(30, vector<bool>(30, false));
                    put(0, x1, y1, exist);
                    put(1, x2, y2, exist);
                    if(check(exist)){
                        out("Yes");
                        return 0;
                    }
                }
            }
        }
    }
    out("No");
}