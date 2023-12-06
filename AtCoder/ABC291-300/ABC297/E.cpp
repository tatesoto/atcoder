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
    ll N,K;cin>>N>>K;
    vector<ll> A(N);
    rep(i, N) cin>>A.at(i);
    sort(all(A));
    //重複要素の削除
    A.erase(unique(all(A)),A.end());

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    set<ll> checked;
    rep(i, A.size()) pq.push(A.at(i)), checked.insert(A.at(i));
    ll ans = 0;
    rep(i, K){
        ll x = pq.top();
        pq.pop();
        if(i == K-1){
            ans = x;
        }
        rep(i, A.size()){
            ll y = x + A.at(i);
            if(!checked.count(y)){
                pq.push(y);
                checked.insert(y);
            }
        }
    }
    out(ans);
}