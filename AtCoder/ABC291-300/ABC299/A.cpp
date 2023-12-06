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
    ll N;cin>>N;
    string S;cin>>S;
    bool judge = false;
    bool check = false;
    string ans = "out";
    rep(i, N){
        if(S.at(i) == '|'){
            if(judge && check) ans = "in";
            if(!judge) judge = true;
        }
        if(S.at(i) == '*' && judge) check = true;
    }
    out(ans);
}