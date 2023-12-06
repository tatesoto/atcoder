#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N;cin>>N;
    priority_queue<pair<ld,ll>> pq;
    rep(i, N){
        ld A, B;cin>>A>>B;
        ld C = A/(A+B);
        pq.push({C, -i});
    }
    while(!pq.empty()){
        auto [x, id] = pq.top();pq.pop();
        out(-id + 1);
    }
}