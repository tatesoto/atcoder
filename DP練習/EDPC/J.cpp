#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;

ll N;
vector<vector<vector<ld>>> dp;
ld dfs(ll i,ll j,ll k){
    if(dp.at(i).at(j).at(k)!=-1) return dp.at(i).at(j).at(k);
    if(i==0&&j==0&&k==0) return 0.0; 
    ld res=0.0;
    if(i>0) res+=dfs(i-1,j,k)*i;
    if(j>0) res+=dfs(i+1,j-1,k)*j;
    if(k>0) res+=dfs(i,j+1,k-1)*k;
    res+=N;
    res/=(ld)(i+j+k);
    return dp.at(i).at(j).at(k)=res;
} 

int main() {
    cin>>N;
    vector<ll> sushi_cnt={0,0,0,0};
    dp.resize(N+1,vector<vector<ld>>(N+1,vector<ld>(N+1,-1)));
    rep(i,N){
        ll c;cin>>c;
        sushi_cnt.at(c)++;
    }
    dfs(sushi_cnt.at(1),sushi_cnt.at(2),sushi_cnt.at(3));
    cout<<fixed<<setprecision(14);
    out(dfs(sushi_cnt.at(1),sushi_cnt.at(2),sushi_cnt.at(3)));
}