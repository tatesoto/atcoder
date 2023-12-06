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

vector<pair<ll,ll>> existvector(Grid G){
    vector<pair<ll,ll>> res;
    ll si, sj;
    rep(i, 4){
        rep(j, 4){
            if(G[i][j] == '#'){
                si = i;
                sj = j;
            }
        }
    }
    res.push_back({si, sj});
    vector<vector<bool>> seen(4, vector<bool>(4, false));
    queue<pair<ll,ll>> q;
    q.push({si, sj});
    seen[si][sj] = true;
    while(!q.empty()){
        auto [x, y] = q.front();q.pop();
        rep(dir, 4){
            ll nx = x + dx[dir];
            ll ny = y + dy[dir];
            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4)continue;
            if(G[nx][ny] == '.') continue;
            if(seen[nx][ny]) continue;
            res.push_back({nx-si, ny-sj});
            seen[nx][ny] = true;
            q.push({nx, ny});
        } 
    }
    return res;
}

vector<vector<pair<ll,ll>>> exist;
bool put(ll id, ll i, ll j, vector<vector<bool>> &judge){
    auto [si, sj] = exist[id][0];
    ll di = i - si, dj = j - sj;
    for(auto p:exist[id]){
        auto [ti, tj] = p;
        ll ni = ti + di;
        ll nj = tj + dj;
        if(ni < 0 || ni >= 4 || nj < 0 || nj >= 4) return false;
        if(judge[ni][nj]) return false;
        judge[ni][nj] = true;
    }
    return true;
}

int main() {
    vector<Grid> G(3);
    rep(i, 3){
        rep(j, 4){
            string S;cin>>S;
            G[i].push_back(S);
        }
    }
    ll cnt = 0;
    rep(i, 3){
        rep(j, 4){
            rep(k, 4){
                if(G[i][j][k] == '#') cnt++;
            }
        }
    }
    if(cnt != 16){
        out("No");
        return 0;
    }
    exist.resize(12);
    rep(i, 3){
        exist[i] = existvector(G[i]);
        rep(j, exist[i].size()){
            auto p = exist[i][j];
            if(i == 0){
                exist[i+3].push_back(p);
                exist[i+6].push_back(p);
                exist[i+9].push_back(p);
            }
            auto [x, y] = p;
            exist[i+3].push_back({-y, x});
            exist[i+6].push_back({-x, -y});
            exist[i+9].push_back({y, -x});
        }
    }
    rep(i, 4){
        rep(j, 4){
            rep(k, 4){
                rep(l, 4){
                    rep(m, 4){
                        rep(n, 4){
                            vector<vector<bool>> judge(4, vector<bool>(4, false));
                            if(put(0, i, j, judge) && put(1, k, l, judge) && put(2, m, n, judge)){
                                out("Yes");
                                return 0;
                            }
                            judge.resize(4, vector<bool>(4, false));
                            if(put(3, i, j, judge) && put(4, k, l, judge) && put(5, m, n, judge)){
                                out("Yes");
                                return 0;
                            }
                            judge.resize(4, vector<bool>(4, false));
                            if(put(6, i, j, judge) && put(7, k, l, judge) && put(8, m, n, judge)){
                                out("Yes");
                                return 0;
                            }
                            judge.resize(4, vector<bool>(4, false));
                            if(put(9, i, j, judge) && put(10, k, l, judge) && put(11, m, n, judge)){
                                out("Yes");
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    out("No");
}
