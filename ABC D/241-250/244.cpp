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
    set<string> a={"RGB","GBR","BRG"};
    string S,T;
    rep(i,3){
        char s;
        cin>>s;
        S+=s;
    }
    rep(i,3){
        char t;
        cin>>t;
        T+=t;
    }
    if(a.count(S)^a.count(T)){
        out("No");
    }
    else{
        out("Yes");
    }
}