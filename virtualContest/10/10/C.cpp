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

ll K;
vector<vector<ll>> C;
string solve(string ans, ll a, ll b){
    ll n = a + b;
    if(a == 0){
        rep(i, n){
            ans.push_back('b');
        }
        return ans;
    }
    if(b == 0){
        rep(i, n){
            ans.push_back('a');
        }
        return ans;
    }
    if(K <= C[a+b-1][a-1]){
        ans.push_back('a');
        return solve(ans, a-1, b);
    }
    else{
        K -= C[a+b-1][a-1];
        ans.push_back('b');
        return solve(ans, a, b-1);
    }
}

int main() {
    ll A, B;cin>>A>>B>>K;
    C.resize(61);
    C[0].push_back(1);
    for(int i = 1;i <= 60; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0 || j == i) C[i].push_back(1);
            else{
                ll n = C[i-1][j-1] + C[i-1][j];
                C[i].push_back(n);
            }
        }
    }
    string ans = "";
    out(solve(ans, A, B));
}