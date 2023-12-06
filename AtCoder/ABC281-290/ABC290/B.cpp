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
    ll N,K;cin>>N>>K;
    string S;cin>>S;
    string T = "";
    ll cnt = 0;
    rep(i, N){
        if(S.at(i) == 'o' && cnt < K){
            T.push_back('o');
            cnt++;
        }
        else{
            T.push_back('x');
        }
    }
    out(T);
}