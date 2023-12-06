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
    vector<vector<ll>> paper(1001,vector<ll>(1001,0));
    vector<vector<ll>> s(1001,vector<ll>(1001,0));
    ll N;cin>>N;
    rep(i,N){
        ll lx,ly,rx,ry;
        cin>>lx>>ly>>rx>>ry;
        paper.at(lx).at(ly)++;
        paper.at(rx).at(ry)++;
        paper.at(lx).at(ry)--;
        paper.at(rx).at(ly)--;
    }
    rep(i,1001){
        rep(j,1001){
            if(j==0) s.at(i).at(j)+=paper.at(i).at(j);
            else{
                s.at(i).at(j)=s.at(i).at(j-1)+paper.at(i).at(j);
            }
        }
    }
    rep(j,1001){
        rep(i,1001){
            if(i==0) continue;
            else{
                s.at(i).at(j)=s.at(i-1).at(j)+s.at(i).at(j);
            }
        }
    }
    vector<ll> v(N+1,0);
    rep(i,1001){
        rep(j,1001){
            v.at(s.at(i).at(j))++;
        }
    }
    for(ll i=1;i<=N;i++){
        out(v.at(i));
    }
}