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

//約数列挙(※sortなし)
ll divisor(ll N){
    vector<ll> ans;
    for(ll i=1;i*i<=N;i++){
        if(N%i==0){
            ans.push_back(i);
            if(i!=N/i){
                ans.push_back(N/i);
            }
        }
    }
    return ans.size();
}

int main() {
    ll N;cin>>N;
    vector<ll> d(N+1);
    for(ll i=1;i<N;i++){
        d.at(i) = divisor(i);
    }
    ll ans = 0;
    for(ll i=1;i<N;i++){
        ans += d.at(i)*d.at(N-i);
    }
    out(ans);
}