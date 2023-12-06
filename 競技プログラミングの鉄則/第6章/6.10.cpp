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

ll CtoI(char C){
    if(C=='W'){
        return 0;
    }
    else if(C=='B'){
        return 1;
    }
    else{
        return 2;
    }
}

int main() {
    ll N;cin>>N;
    char C;cin>>C;
    ll ans=0;
    rep(i,N){
        char a;cin>>a;
        ans+=CtoI(a);
    }
    ans%=3;
    if(ans==CtoI(C)) out("Yes");
    else out("No");
}