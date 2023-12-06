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
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N;cin>>N;
    ll X, Y;
    ll m = 1;
    ll range = 1024;
    while(range > 1){
        range /= 2;
        out("? "<<m<<" "<<min(N, m + range -1)<<" "<<1<<" "<<N);
        ll num;cin>>num;
        if(num == range){
            m += range;
        }
    }
    X = m;
    m = 1;
    range = 1024;
    while(range > 1){
        range /= 2;
        out("? "<<1<<" "<<N<<" "<<m<<" "<<min(N, m + range -1));
        ll num;cin>>num;
        if(num == range){
            m += range;
        }
    }
    Y = m;
    cout<<"! "<<X<<" "<<Y<<endl;
}