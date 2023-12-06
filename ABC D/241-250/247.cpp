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
    queue<vector<ll>> dq;
    rep(i,Q){
        ll q;cin>>q;
        if(q==1){
            ll x,c;cin>>x>>c;
            dq.push({x,c});
        }
        else{
            ll c;cin>>c;
            ll ans=0;
            while(c>0){
                ll num=dq.front().at(1);
                ll value=dq.front().at(0);
                if(c>=num){
                    c-=num;
                    ans+=num*value;
                    dq.pop();
                }
                else{
                    dq.front().at(1)=num-c;
                    ans+=c*value;
                    break;
                }
            }
            out(ans);
        }
    }
}