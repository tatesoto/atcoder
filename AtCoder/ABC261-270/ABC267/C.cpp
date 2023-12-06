#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,M;
    cin>>N>>M;
    vector<ll> data(N);
    rep(i,N){
        cin>>data.at(i);
    }

    vector<ll> s(N+1,0); //すべて0のN+1個の配列
    for(ll i=0;i<N;i++){
        s.at(i+1)=s.at(i)+data.at(i); //帰納的に埋めていく
    }

    vector<ll> dp(N,0);
    ll ans=0;
    for(ll i=0;i<M;i++){
        dp.at(0)+=(i+1)*data.at(i);
    }
    ans=dp.at(0);
    for(ll i=0;i+M<N;i++){
        //区間[left,right)の総和を求める;
        ll left,right;
        left=i;
        right=i+M;
        ll x=s.at(right)-s.at(left);
        dp.at(i+1)=dp.at(i)+M*(data.at(i+M))-x;
        ans=max(ans,dp.at(i+1));
    }
    out(ans);
}