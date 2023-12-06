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
    ll N,M;cin>>N>>M;
    vector<string> s(N);
    rep(i,N){
        cin>>s.at(i);
    }
    ll cnt=0;
    rep(i,N){
        for(ll j=i+1;j<N;j++){
            bool judge=true;
            rep(k,M){
                if(s.at(i).at(k)=='x'&&s.at(j).at(k)=='x'){
                    judge=false;
                }
            }
            if(judge){
                cnt++;
            }
        }
    }
    out(cnt);
}