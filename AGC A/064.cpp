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
    vector<ll> A;
    ll now = N;
    while(now > 1){
        rep(i, now-2){
            A.push_back(now);
            A.push_back(now-1);
        }
        A.push_back(now);
        now -= 2;
        if(now <= 1) break;
    }
    rep(i, N-2) A.push_back(i+1);
    A.push_back(N);
    A.push_back(N-1);
    for(auto a : A) cout << a << " ";
    cout << endl;
}
