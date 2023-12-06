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
    string S;cin>>S;
    ll check = 0;
    rep(i, 8){
        if(S.at(i) == 'B'){
            check += i;
        }
    }
    if(check%2 == 0){
        out("No");
        return 0;
    }
    ll king = -1;
    rep(i, 8){
        if(S.at(i) == 'R'){
            king *= -1;
        }
        if(S.at(i) == 'K'){
            if(king == 1) out("Yes");
            else{
                out("No");
            }
        }
    }
}