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
    vector<deque<char>> s(3);
    rep(i,3){
        string tmp;cin>>tmp;
        for(auto c:tmp) s[i].push_back(c);
    }
    ll now = 0;
    while(true){
        if(s[now].empty()){
            out((char)(now + 'A'));
            return 0;
        }
        char c = s[now].front();
        s[now].pop_front();
        now = c - 'a';
    }
}
