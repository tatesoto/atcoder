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
    ll N;cin>>N;
    string R, C;cin>>R>>C;
    vector<string> S(N);
    rep(i, N)rep(j, N) S[i].push_back('.');
    auto put = [&](char c, vector<ll> pmt){
        rep(i, N){
            if(S[i][pmt[i]] != '.') return false;
            S[i][pmt[i]] = c;
        }
        return true;
    };
    auto check = [&](){
        rep(i, N){
            rep(j, N){
                if(S[i][j] == '.') continue;
                if(S[i][j] != R[i]) return false;
                break;
            }
        }
        rep(j, N){
            rep(i, N){
                if(S[i][j] == '.') continue;
                if(S[i][j] != C[j]) return false;
                break;
            }
        }
        return true;
    };
    vector<ll> apmt(N), bpmt(N), cpmt(N);
    rep(i, N) apmt[i] = i, bpmt[i] = i, cpmt[i] = i; 
    do{
        do{
            do{
                if(put('A', apmt) && put('B', bpmt) && put('C', cpmt) && check()){
                    out("Yes");
                    rep(i, N){
                        out(S[i]);
                    }
                    return 0;
                }
                rep(i, N)rep(j, N) S[i][j] = '.';
            }while(next_permutation(all(cpmt)));
        }while(next_permutation(all(bpmt)));
    }while(next_permutation(all(apmt)));
    out("No");
}