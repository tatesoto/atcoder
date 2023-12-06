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


//left,rightは0-indexed;
ll v_sum(vector<ll> v,ll left,ll right){
    return v.at(right+1)-v.at(left);
}


ll G_sum(vector<vector<ll>> G,ll uplefth,ll upleftw,ll downrighth,ll downrightw){
    return G.at(downrighth+1).at(downrightw+1)+G.at(uplefth).at(upleftw)-G.at(uplefth).at(downrightw+1)-G.at(downrighth+1).at(upleftw);
}


int main(){
    ll N;
    cin>>N;
    vector<ll> a(N);
    for(ll i=0;i<N;i++){
        cin>>a.at(i);
    }

    //累積和sの定義
    vector<ll> s(N+1,0); //すべて0のN+1個の配列
    for(ll i=0;i<N;i++){
        s.at(i+1)=s.at(i)+a.at(i); //帰納的に埋めていく
    }


    ll H,W;cin>>H>>W;
    vector<vector<ll>> G(H,vector<ll>(W));
    rep(i,H){
        rep(j,W){
            cin>>G.at(i).at(j);
        }
    }
    vector<vector<ll>> gs(H+1,vector<ll>(W+1,0));
    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            gs.at(i).at(j+1)=gs.at(i).at(j)+G.at(i).at(j);
        }
    }
    for(ll i=0;i<W;i++){
        for(ll j=0;j<H;j++){
            gs.at(i+1).at(j)=gs.at(i).at(j)+gs.at(i+1).at(j);
        }
    }
    out(G_sum(G,0,0,1,2));
}