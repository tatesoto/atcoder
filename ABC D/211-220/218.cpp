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
#define ull unsigned long long

int main() {
    ull N;cin>>N;
    vector<ull> x(N),y(N);
    set<ull> xy;
    rep(i,N){
        cin>>x.at(i)>>y.at(i);
        xy.insert(x.at(i)*10000000000+y.at(i));
    }
    ull count=0;
    rep(i,N){
        rep(j,N){
            if(x.at(i)<x.at(j)&&y.at(i)<y.at(j)&&xy.count(x.at(i)*10000000000+y.at(j))&&xy.count(x.at(j)*10000000000+y.at(i))){
                count++;
            }
        }   
    }
    out(count);
}