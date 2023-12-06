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

class SegmentTree{
    public:
    ll siz;
    vector<ll> dat;

    void init(ll N){
        siz=1;
        while(siz<N) siz*=2;
        rep(i,2*siz-1) dat.push_back(0);
    }

    void update(ll pos,ll x){
        pos=pos+siz-1;
        dat.at(pos)=x;
        while(pos>0){
            pos=(pos-1)/2;
            dat.at(pos)=max(dat.at(pos*2+1),dat.at(pos*2+2));
        }
    }

    ll __query(ll a,ll b,ll k,ll l,ll r){
        if(r<=a||b<=l) return -INF;
        if(a<=l&&r<=b) return dat.at(k);
        else{
            ll vl=__query(a,b,2*k+1,l,(l+r)/2);
            ll vr=__query(a,b,2*k+2,(l+r)/2,r);
            return max(vl,vr);
        }
    }
    ll query(ll a,ll b){
        return __query(a,b,0,0,siz);
    }
};

int main() {
    ll N,Q;cin>>N>>Q;
    SegmentTree Z;
    Z.init(N);
    rep(i,Q){
        ll q;cin>>q;
        if(q==1){
            ll pos,x;cin>>pos>>x;
            pos--;
            Z.update(pos,x);
        }
        else{
            ll l,r;cin>>l>>r;
            l--;
            r--;
            out(Z.query(l,r));
        }
    }
}