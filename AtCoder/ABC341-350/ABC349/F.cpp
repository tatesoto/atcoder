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
    Graph G(3, vector<ll>(3));
    rep(i, 3) {
        rep(j, 3) {
            cin >> G[i][j];
        }
    }
    Grid board(3, string(3, '.'));
    auto is_bingo = [&](char c) -> bool {
        rep(i, 3) {
            bool ok = true;
            rep(j, 3) {
                if(board[i][j] != c) {
                    ok = false;
                    break;
                }
            }
            if(ok) return true;
        }
        rep(j, 3) {
            bool ok = true;
            rep(i, 3) {
                if(board[i][j] != c) {
                    ok = false;
                    break;
                }
            }
            if(ok) return true;
        }
        if(board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
        if(board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;
        return false;
    };
    auto tictactoe = [&](auto tictactoe, ll cnt) -> ll {
        if(cnt == 9) {
            ll takahashi = 0, aoki = 0;
            rep(i, 3) {
                rep(j, 3) {
                    if(board[i][j] == 'o') takahashi += G[i][j];
                    else if(board[i][j] == 'x') aoki += G[i][j];
                }
            }
            if(takahashi > aoki) {
                return 1;
            }
            else {
                return 0;
            }
        }
        rep(i, 3) {
            rep(j, 3) {
                if(board[i][j] == '.') {
                    if(cnt % 2 == 0) {
                        board[i][j] = 'o';
                        if(is_bingo('o')) {
                            board[i][j] = '.';
                            return 1;
                        }
                        if(tictactoe(tictactoe, cnt + 1) == 1) {
                            board[i][j] = '.';
                            return 1;
                        }
                        board[i][j] = '.';
                    }
                    else {
                        board[i][j] = 'x';
                        if(is_bingo('x')) {
                            board[i][j] = '.';
                            return 0;
                        }
                        if(tictactoe(tictactoe, cnt + 1) == 0) {
                            board[i][j] = '.';
                            return 0;
                        }
                        board[i][j] = '.';
                    }
                }
            }
        }
        if(cnt % 2 == 0) {
            return 0;
        }
        else {
            return 1;
        }
    };
    ll res = tictactoe(tictactoe, 0);
    if(res == 1) out("Takahashi");
    else if(res == 0) out("Aoki");
    else out("Draw"); 
}