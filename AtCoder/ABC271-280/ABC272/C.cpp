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
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    sort(all(a));
    reverse(all(a));
    ll cnt0=0;
    ll cnt1=0;
    ll ans0=0;
    ll ans1=0;
    rep(i,N){
        if(a.at(i)%2==0 && cnt0<2){
            cnt0++;
            ans0+=a.at(i);
        }
        else if(a.at(i)%2==1 && cnt1<2){
            cnt1++;
            ans1+=a.at(i);
        }
    }
    if(cnt0<2&&cnt1<2){
        out("-1");
    }
    else if(cnt0<2){
        out(ans1);
    }
    else if(cnt1<2){
        out(ans0);
    }
    else{
        out(max(ans0,ans1));
    }
}