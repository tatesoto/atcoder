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
    string s;cin>>s;
    if(s == "tourist") out(3858);
    if(s == "ksun48") out(3679);
    if(s == "Benq") out(3658);
    if(s == "Um_nik") out(3648);
    if(s == "apiad") out(3638);
    if(s == "Stonefeang") out(3630);
    if(s == "ecnerwala") out(3613);
    if(s == "mnbvmar") out(3555);
    if(s == "newbiedmy") out(3516);
    if(s == "semiexp") out(3481);
}
