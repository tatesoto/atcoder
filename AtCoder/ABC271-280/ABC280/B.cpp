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
    vector<ll> s(N);
    rep(i,N){
        cin>>s.at(i);
    }
    vector<ll> a(N);
    ll sum=0;
    rep(i,N){
        a.at(i)=s.at(i)-sum;
        sum+=a.at(i);
    }
    rep(i,N){
        cout<<a.at(i);
        if(i!=N-1){
            cout<<" ";
        }
    }
    cout<<endl;
}