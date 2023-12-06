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

bool judge(ll h,ll m){
    ll a=h/10;
    ll b=h%10;
    ll c=m/10;
    ll d=m%10;
    if(10*a+c<24&&10*b+d<60) return true;
    else return false;
}

int main() {
    ll H,M;cin>>H>>M;
    while(true){
        if(judge(H,M)) break;
        M++;
        if(M==60){
            H++;
            M=0;
        }
        if(H==24){
            H=0;
        }
    }
    cout<<H<<" "<<M<<endl;
}