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


int main() {
    ll N;cin>>N;
    ll lx,rx,ly,ry;
    lx=1;
    rx=(N-1)/2+1;
    ly=1;
    ry=(N-1)/2+1;
    ll ansx,ansy;
    while(1){
        out("? "<<lx<<" "<<rx<<" "<<1<<" "<<N);
        ll T;cin>>T;
        if(T==-1){
            return 0;
        }
        if(T==0){
            ansx=lx;
            break;
        }
        if(T==rx-lx+1){
            ll d;
            d=rx-lx;
            d/=2;
            lx=rx+1;
            rx=lx+d;
            if(T==1 && d==0){
                ansx=lx;
                break;
            }
        }
        else{
            ll d;
            d=rx-lx;
            d/=2;
            rx=lx+d;
            if(T==1 && d==0){
                ansx=lx;
                break;
            }
        }
    }
    while(1){
        out("? "<<1<<" "<<N<<" "<<ly<<" "<<ry);
        ll T;cin>>T;
        if(T==-1){
            return 0;
        }
        if(T==0){
            ansy=ly;
            break;
        }
        if(T==ry-ly+1){
            ll d;
            d=ry-ly;
            d/=2;
            ly=ry+1;
            ry=ly+d;
            if(T==1 && d==0){
                ansy=ly;
                break;
            }
        }
        else{
            ll d;
            d=ry-ly;
            d/=2;
            ry=ly+d;
            if(T==1 && d==0){
                ansy=ly;
                break;
            }
        }
    }
    out("! "<<ansx<<" "<<ansy);
    return 0;
}