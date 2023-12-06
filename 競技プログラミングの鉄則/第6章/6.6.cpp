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
    ll N;cin>>N;
    string S;cin>>S;
    char b=S.at(0);
    ll bcount=1;
    for(ll i=1;i<N;i++){
        if(S.at(i)==b){
            bcount++;
            if(bcount==3){
                out("Yes");
                return 0;
            }
        }
        else{
            bcount=1;
        }
        b=S.at(i);
    }
    out("No");
}