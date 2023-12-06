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
    ll N,X,Y;cin>>N>>X>>Y;
    vector<ll> a(N);
    rep(i,N){
        cin>>a.at(i);
    }
    vector<ll> Grundy(100001);
    rep(i,100001){
        vector<bool> v={false,false,false};
        if(i>=X) v.at(Grundy.at(i-X))=true;
        if(i>=Y) v.at(Grundy.at(i-Y))=true;
        if(v.at(0)==false) Grundy.at(i)=0;
        else if(v.at(1)==false) Grundy.at(i)=1;
        else Grundy.at(i)=2;
    }

    ll Xor_sum=0;
    rep(i,N){
        Xor_sum^=Grundy.at(a.at(i));
    }
    if(Xor_sum!=0){
        out("First");
    }
    else{
        out("Second");
    }
}