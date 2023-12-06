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
    ll A, B;cin>>A>>B;
    ll cnt = 0;
    while(A != B){
        if(A > B){
            ll k = (A-1)/B;
            A = A - k*B;
            cnt+=k;
        }
        else{
            ll k = (B-1)/A;
            B = B - k*A;
            cnt+=k;
        }
    }
    out(cnt);
}