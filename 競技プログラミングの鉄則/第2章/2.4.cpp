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
    ll H,W,N;cin>>H>>W>>N;
    Graph G(H+2,vector<ll>(W+2,0));
    rep(i,N){
        ll a,b,c,d;cin>>a>>b>>c>>d;
        G.at(a).at(b)++;
        G.at(c+1).at(d+1)++;
        G.at(c+1).at(b)--;
        G.at(a).at(d+1)--;
    }
    Graph s(H+1,vector<ll>(W+1,0));
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            s.at(i).at(j)=s.at(i).at(j-1)+G.at(i).at(j);
        }
    }
    for(ll j=1;j<=W;j++){
        for(ll i=1;i<=H;i++){
            s.at(i).at(j)=s.at(i-1).at(j)+s.at(i).at(j);
        }
    }
    for(ll i=1;i<=H;i++){
        for(ll j=1;j<=W;j++){
            cout<<s.at(i).at(j);
            if(j<W){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}