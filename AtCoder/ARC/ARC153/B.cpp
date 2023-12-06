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
    ll H,W;cin>>H>>W;
    vector<string> A(H+1);
    for(ll i=1;i<=H;i++){
        string S;cin>>S;
        S = "$" + S;
        A.at(i) = S;
    } 
    ll Q;cin>>Q;
    vector<ll> _a(Q),_b(Q);
    rep(i,Q){
        ll a,b;cin>>_a.at(i)>>_b.at(i);
    }
    rep(i,Q){
        vector<string> B=A;
        ll a=_a.at(i);
        ll b=_b.at(i);
        for(ll i=1;i<=H;i++){
            for(ll j=1;j<=W;j++){
                if (i<=a){
                    if (j<=b) B.at(i).at(j)=A.at(a+1-i).at(b+1-j);
                    else B.at(i).at(j)=A.at(a+1-i).at(W+b+1-j);
                }
                if (i>a){
                    if (j<=b) B.at(i).at(j)=A.at(H+a+1-i).at(b+1-j);
                    else B.at(i).at(j)=A.at(H+a+1-i).at(W+b+1-j);
                }
            }
            A = B;
        }
    }
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            cout<<A.at(i).at(j);
            if(j==W) cout<<endl;
        }
    }
}