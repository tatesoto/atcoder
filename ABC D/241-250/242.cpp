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

const vector<char> abc={'A','B','C'};
string S;
char tk(ll t,ll k){
    if(t==0){
        return S.at(k);
    }
    else if(k==0){
        ll now=S.at(0)-'A';
        now+=t;
        now%=3;
        return abc.at(now);
    }
    else{
        if(k%2==0){
            char c=tk(t-1,k/2);
            ll now=c-'A';
            now+=1;
            now%=3;
            return abc.at(now);
        }
        else{
            char c=tk(t-1,k/2);
            ll now=c-'A';
            now+=2;
            now%=3;
            return abc.at(now); 
        }
    }
}


int main() {
    cin>>S;
    ll Q;cin>>Q;
    rep(i,Q){
        ll t,k;cin>>t>>k;
        k--;
        out(tk(t,k));
    }
}