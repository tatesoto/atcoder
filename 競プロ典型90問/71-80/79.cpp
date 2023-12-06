#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=1000000007;
using Graph = vector<vector<ll>>;

int main() {
    ll H,W;cin>>H>>W;
    vector<vector<ll>> a(H+1,vector<ll>(W+1));
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            cin>>a.at(i).at(j);
        }
    }
    vector<vector<ll>> b(H+1,vector<ll>(W+1));
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            cin>>b.at(i).at(j);
        }
    }
    ll cnt=0;
    vector<pair<ll,ll>> pm={{0,0},{0,1},{1,0},{1,1}};
    for(ll i=1;i<=H-1;i++){
        for(ll j=1;j<=W-1;j++){
            ll d=b.at(i).at(j)-a.at(i).at(j);
            cnt+=abs(d);
            for(auto p:pm){
                ll ni=i;
                ll nj=j;
                ni+=p.first;
                nj+=p.second;
                a.at(ni).at(nj)+=d;
            }
        }
    }
    for(ll i=1;i<=H;i++){
        if(b.at(i).at(W)-a.at(i).at(W)!=0){
            out("No");
            return 0;
        }
    }
    for(ll j=1;j<=W;j++){
        if(b.at(H).at(j)-a.at(H).at(j)!=0){
            out("No");
            return 0;
        }
    }
    out("Yes");
    out(cnt);
}