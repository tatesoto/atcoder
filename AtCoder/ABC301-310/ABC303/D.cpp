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
    ll X, Y, Z;cin>>X>>Y>>Z;
    string S;cin>>S;
    ll N = S.size();
    vector<vector<ll>> dp(N, vector<ll>(2, INF));
    if(S.at(0) == 'a'){
        chmin(dp.at(0).at(0), X);
        chmin(dp.at(0).at(1), Z+Y);
    }
    else{
        chmin(dp.at(0).at(1), Z+X);
        chmin(dp.at(0).at(0), Y);
    }
    rep(i, N-1){
        if(S.at(i+1) == 'a'){
            chmin(dp.at(i+1).at(0), dp.at(i).at(0) + X);
            chmin(dp.at(i+1).at(0), dp.at(i).at(1) + Z+X);
            chmin(dp.at(i+1).at(1), dp.at(i).at(1) + Y);
            chmin(dp.at(i+1).at(1), dp.at(i).at(0) + Z+Y);
        }
        else{
            chmin(dp.at(i+1).at(0), dp.at(i).at(0) + Y);
            chmin(dp.at(i+1).at(0), dp.at(i).at(1) + Z+Y);
            chmin(dp.at(i+1).at(1), dp.at(i).at(1) + X);
            chmin(dp.at(i+1).at(1), dp.at(i).at(0) + Z+X);
        }
    }
    out(min(dp.at(N-1).at(0), dp.at(N-1).at(1)));
}