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

int main() {
    ll H,W,K;cin>>H>>W>>K;
    vector<vector<char>> v(H+1,vector<char>(W+1));
    ll already=0;
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            cin>>v.at(i).at(j);
            if(v.at(i).at(j)=='#'){
                already++;
            }
        }
    }
    for(ll bit=0;bit<(1<<H);bit++){
        ll plus=0;
        for(ll i=0;i<H;i++){
            if(bit && (1<<i)){
                ll cnt=0;
                for(ll j=1;j<=W;j++){
                    if(v.at(i-1).at(j)=='.'){
                        cnt++;
                    }
                }
                plus+=cnt;
            }
        }
    }
}