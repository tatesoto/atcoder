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
    pair<ll,ll> s, t;
    rep(i, 2){
        char a, b;cin>>a>>b;
        a -= 'A';
        b -= 'A';
        if(i == 0){
            s = make_pair(a, b);
        }else{
            t = make_pair(a, b);
        }
    }
    auto d = [](pair<ll,ll> p){
        return min(abs(p.first - p.second)%5, 5 - abs(p.first - p.second)%5);
    };
    d(s) == d(t)? out("Yes") : out("No");
}