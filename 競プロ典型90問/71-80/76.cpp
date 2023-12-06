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
    vector<ll> a(N);
    rep(i,N) cin>>a.at(i);
    //s(i)は最初から数えてi番目までの和
    vector<ll> s(2*N+1,0);
    for(ll i=1;i<=2*N;i++){
        s.at(i)=s.at(i-1)+a.at((i-1)%N);
    }
    if(s.at(N)%10!=0){
        out("No");
        return 0;
    }
    ll l=s.at(N)/10;
    for(ll i=0;i<N;i++){
        for(ll j=i+1;s.at(j)-s.at(i)<=l;j++){
            if(s.at(j)-s.at(i)==l){
                out("Yes");
                return 0;
            }
        }
    }
    out("No");
}