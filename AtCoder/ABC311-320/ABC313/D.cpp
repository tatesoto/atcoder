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

vector<ll> f(vector<ll> T, ll N, ll K){
    vector<ll> res(N);
    ll tmp = 0;
    rep(i, T.size()){
        if(i == 0){
            rep(j, K){
                tmp^=T.at((i+j)%N);
            }
        }
        else{
            tmp^=T.at((i+K-1)%N);
            tmp^=T.at((i-1)%N);
        }
        res.at((i+(K/2))%N) = tmp;
    }
    return res;
}

int main() {
    ll N, K;cin>>N>>K;
    vector<ll> T(N);
    rep(i, N){
        cout<<"? ";
        rep(j, K){
            cout<<(i+j)%N + 1<<" ";
        }
        cout<<"\n";
        cin>>T.at(i);
    }
    vector<ll> res = T;
    rep(i, N){
        res = f(res, N, K);
        rep(i, N){
            cout<<res.at(i)<<" ";
        }
        cout<<"\n";
    }
    cout<<"! ";
    rep(i, N){
        cout<<res.at(i)<<" ";
    }
    cout<<"\n";
    return 0;
}
