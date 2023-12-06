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
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N,K;cin>>N>>K;
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    map<ll,ll> mp;
    rep(i,N) mp[a.at(i)]++;
    vector<pair<ll,ll>> ln;
    ll n = N;
    ll before = 0;
    for(auto p:mp){
        ll l = p.first - before;
        ln.push_back({l, n});
        before = p.first;
        n -= p.second;
    }
    vector<ll> s(ln.size() + 1, 0);
    rep(i, ln.size()){
        s.at(i + 1) = s.at(i) + ln.at(i).first*ln.at(i).second;
    }
    ll index = 0;
    rep(i, ln.size()+1){
        if(s.at(i) >= K) break;
        index = i;
    }

    // cout<<"mp"<<endl;
    // for(auto p:mp){
    //     cout<<p.first<<" "<<p.second<<endl;        
    // }
    // cout<<"ln" <<endl;
    // for(auto p: ln ){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    // cout<<"s"<<endl;
    // for(auto x: s){
    //     cout<<x<<endl;
    // }
    // cout<<"index"<<endl;
    // out(index);

    ll C = K - s.at(index);
    ll p = C/ln.at(index).second;
    ll r = C%ln.at(index).second;
    ll cicle = 0;
    rep(i, index) cicle += ln.at(i).first;
    cicle += p;
    rep(i, N){
        if(a.at(i) <= cicle) cout<<0<<" ";
        else{
            if(r > 0){
                cout<<a.at(i) - cicle -1 <<" ";
                r--;
            }
            else{
                cout<<a.at(i) - cicle<<" ";
            }
        }
    }
    cout<<endl;
}