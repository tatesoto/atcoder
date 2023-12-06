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
    vector<ll> s1(3,0);
    vector<ll> s2(3,0);
    N--;
    ll r = N%100;
    s1.at(2)=(r%10);
    s2.at(2)=(r/10);
    ll p = N%1000;
    s2.at(1)=(p/100);
    p = N%10000;
    p/=1000;
    s1.at(1)=(p);
    p = N%100000;
    p/=10000;
    s1.at(0)=(p);
    p=N/100000;
    p+=1;
    s2.at(0)=(p);
    cout<<s2.at(0)<<s2.at(0)<<s1.at(0)<<s1.at(1)<<s2.at(1)<<s2.at(1)<<s2.at(2)<<s1.at(2)<<s2.at(2)<<endl;
}