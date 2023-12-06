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
    string ans="";
    rep(i,N){
        ans.push_back(S.at(i));
        if(i < N-1 && S.at(i) == 'n' && S.at(i+1) == 'a'){
            ans.push_back('y');
        }
    }
    out(ans);
}