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
    vector<Grid> P(3, Grid(4));
    rep(i, 3)rep(j, 4) cin>>P[i][j];
    auto rotate = [&](Grid g){
        Grid res(4, string(4, '.'));
        rep(i, 4)rep(j, 4){
            res[j][3-i] = g[i][j];
        }
        return res;
    };
    auto put = [&](Grid &board, Grid g, ll x, ll y){
        rep(i, 4)rep(j, 4){
            if(g[i][j] == '#'){
                if(x+i < 0 || y+j < 0 || x+i >= 4 || y+j >= 4) return false;
                if(board[x+i][y+j] == '#') return false;
                board[x+i][y+j] = '#';
            }
        }
        return true;
    };
    auto check = [&](Grid board){
        rep(i, 4)rep(j, 4){
            if(board[i][j] == '.') return false;
        }
        return true;
    };
    rep(rotb, 4){
        P[1] = rotate(P[1]);
        rep(rotc, 4){
            P[2] = rotate(P[2]);
            for(ll i = -3; i <= 3; i++)for(ll j = -3; j <= 3; j++)for(ll k = -3; k <= 3; k++)for(ll l = -3; l <= 3; l++)for(ll m = -3; m <= 3; m++)for(ll n = -3; n <= 3; n++){
                Grid board(4, string(4, '.'));
                if(!put(board, P[0], i, j)) continue;
                if(!put(board, P[1], k, l)) continue;
                if(!put(board, P[2], m, n)) continue;
                if(check(board)){
                    out("Yes");
                    return 0;
                }
            }
        }
    }
    out("No");
}
