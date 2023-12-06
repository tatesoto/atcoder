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

//P進法のハッシュ
ll P=100LL;

//ハッシュ値を保存
vector<ll> Hash;
//Pのn乗を事前計算して保存
vector<ll> powerP;

ll Hash_value(ll l,ll r){
    ll val=(Hash.at(r)-Hash.at(l-1)*powerP.at(r-l+1))%mod;
    if(val<0) val+=mod;
    return val;
}

int main() {
    ll N;cin>>N;
    string S;cin>>S;
    Hash.resize(N+1);
    powerP.resize(N+1);

    //ハッシュ値を入力していく
    Hash.at(0)=0;
    rep(i,N){
        Hash.at(i+1)=(Hash.at(i)*P+((ll)(S.at(i)-'a')+1))%mod;
    }
    //Pのn乗の事前計算
    powerP.at(0)=1;
    rep(i,N){
        powerP.at(i+1)=(powerP.at(i)*P)%mod;
    }

}