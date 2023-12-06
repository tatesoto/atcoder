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

//約数列挙(※sortなし)
vector<ll> divisor(ll N){
    vector<ll> ans;
    for(ll i=1;i*i<=N;i++){
        if(N%i==0){
            ans.push_back(i);
            if(i!=N/i){
                ans.push_back(N/i);
            }
        }
    }
    return ans;
}

int main() {
    ll N;cin>>N;
    map<ll,ll> mp;
    vector<ll> a(N);
    rep(i,N){
        ll A;cin>>A;
        a.at(i)=A;
        mp[A]++;
    }
    sort(all(a));
    ll ans=0;
    rep(i,N){
        ll n=a.at(i);
        vector<ll> div=divisor(n);
        sort(all(div));
        ll siz=div.size()-1;
        for(ll j=0;j<=siz;j++){
            if(div.at(j)==div.at(siz-j)){
                ans+=mp[div.at(j)]*(mp[div.at(j)]);
            }
            else{
                ans+=mp[div.at(j)]*mp[div.at(siz-j)];
            }
        }
    }
    out(ans);
}