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
    string S,T;cin>>S>>T;
    ll s=S.size();
    ll t=T.size();
    if(S==T){
        out("Yes");
        return 0;
    }
    for(ll i=0;i<=s-t;i++){
        bool judge=true;
        for(ll j=0;j<t;j++){
            if(S.at(i+j)!=T.at(j)){
                judge=false;
            }
        }
        if(judge){
            out("Yes");
            return 0;
        }
    }
    out("No");
}