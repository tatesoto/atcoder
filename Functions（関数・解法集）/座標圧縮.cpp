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

//座標圧縮、計算量はNlogN、0-indexed;
vector<ll> Ncompression(vector<ll> v){
    vector<ll> T,ans;
    rep(i,v.size()){
        T.push_back(v.at(i));
    }
    sort(all(T));
    T.erase(unique(all(T)),T.end());
    rep(i,v.size()){
        ll x=lower_bound(all(T),v.at(i))-T.begin();
        ans.push_back(x);
        //1-indexed
        // ans.at(i)++;
    }
    return ans;
}

//座標圧縮、計算量はNlogN、0-indexed;
vector<ll> Scompression(vector<string> v){
    vector<string> T;
    vector<ll> ans;
    rep(i,v.size()){
        T.push_back(v.at(i));
    }
    sort(all(T));
    T.erase(unique(all(T)),T.end());
    rep(i,v.size()){
        ll x=lower_bound(all(T),v.at(i))-T.begin();
        ans.push_back(x);
        //1-indexed
        // ans.at(i)++;
    }
    return ans;
}


int main() {
    vector<ll> v={3,14,15,9,2,65,3};
    vector<string> w={"pen", "pineapple", "apple", "pen"};
    vector<ll> s=Ncompression(v);
    vector<ll> t=Scompression(w);
    for(auto x:s){
        out(x);
    }
    for(auto x:t){
        out(x);
    }
}