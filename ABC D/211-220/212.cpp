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
    ll Q;cin>>Q;
    priority_queue<ll,vector<ll>,greater<ll>> m;
    vector<ll> s;
    s.push_back(0);
    ll count2=0;
    rep(i,Q){
        ll p;cin>>p;
        if(p==1){
            ll x;cin>>x;
            x-=s.at(count2);
            m.push(x);
        }
        else if(p==2){
            ll x;cin>>x;
            s.push_back(s.at(count2)+x);
            count2++;
        }
        else{
            ll x=m.top();m.pop();
            out(x+s.at(s.size()-1));
        }
    }
}