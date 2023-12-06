#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll R,C;cin>>R>>C;
    vector<vector<char>> B(R, vector<char>(C));
    rep(i, R){
        rep(j, C){
            cin>>B.at(i).at(j);
        }
    }
    vector<vector<bool>> judge(R, vector<bool>(C, false));
    rep(i, R){
        rep(j, C){
            char c = B.at(i).at(j);
            if(c == '.' || c == '#') continue;
            ll n = c - '0';
            for(ll k = i - n;k <= i + n;k++){
                for(ll l = j - n;l <= j + n;l++){
                    if(k < 0 || k >= R || l < 0 || l >= C) continue;
                    if(abs(k-i) + abs(l-j) <= n){
                        judge.at(k).at(l) = true;
                    }
                }
            }
        }
    }
    rep(i, R){
        rep(j, C){
            if(judge.at(i).at(j)){
                cout<<".";
            }
            else{
                cout<<B.at(i).at(j);
            }
            if(j == C-1){
                cout<<endl;
            }
        }
    }
}