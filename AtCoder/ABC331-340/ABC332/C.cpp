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
    ll N, M;cin>>N>>M;
    string s;cin>>s;
    s.push_back('0');
    ll ans = 0;
    ll cnt1 = 0, cnt2 = 0;
    rep(i, N+1){
        if(s[i] == '0'){
            chmax(ans, max(cnt1-M, 0LL)+cnt2);
            cnt1 = 0;
            cnt2 = 0;
        }
        else if(s[i] == '1'){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    out(ans);
}