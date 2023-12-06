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
    string S;cin>>S;
    ll cnt = 0;
    while(!S.empty()){
        char c = S.back();
        if(c=='0'){ 
            cnt++;
            S.pop_back();
            if(S.back()=='0'){
                S.pop_back();
            }
        }
        else{
            cnt++;
            S.pop_back();
        }
    }
    out(cnt);
}