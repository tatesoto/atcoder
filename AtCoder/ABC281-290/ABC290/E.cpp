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
    vector<ll> A(2*N - 1);
    rep(i, N){
        ll a;cin>>a;
        A.at(2*i) = a;
        if(i != N-1){
            A.at(2*i + 1) = -1;
        }
    }
    vector<ll> R(2*N - 1);
    ll i = 0, j = 0;
    while(i < A.size()){
        while (i-j >= 0 && i+j < A.size() && A[i-j] == A[i+j]) ++j;
        R[i] = j;
        int k = 1;
        while (i-k >= 0 && k+R[i-k] < j) R[i+k] = R[i-k], ++k;
        i += k; j -= k;
    }
    ll cnt = 1;
    ll ans = 0;
    rep(i, 2*N - 1){
        ll r = cnt - R[i];
        ans += (r + 1)/2;
        if(i < N-1) cnt++;
        else cnt--;
    }
    out(ans);
}