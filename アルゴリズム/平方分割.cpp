#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

const ll sqrtN = sqrt(2*1e5);
struct SqrtDecomposition {
    ll N; //データ数
    ll K; //パケット数
    vector<ll> data;
    SqrtDecomposition(ll n) : N(n) {
        K = (N + sqrtN - 1) / sqrtN;
        data.assign(K*sqrtN, 0);
    }
};

int main() {
    
}