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
    ll N;cin>>N;
    ll X;cin>>X;
    vector<pair<ll,ll>> coin(N);
    rep(i,N) cin>>coin.at(i).first>>coin.at(i).second;
    queue<pair<ll,ll>> q;
    q.push({0,-1});
    rep(i,N){
        vector<bool> check(10001,false);
        while(!q.empty()){
            pair<ll,ll> p = q.front();
            if(p.second == i){
                break;
            }
            q.pop();
            rep(j,coin.at(i).second+1){
                ll rec=p.first+j*coin.at(i).first;
                if(rec>10000){
                    continue;
                }
                if(!check.at(rec)){
                    check.at(rec)=true;
                    q.push({rec,i});
                }
            }
        }
    }
    while(!q.empty()){
        if(X==q.front().first){
            out("Yes");
            return 0;
        }
        q.pop();
    }
    out("No");
}