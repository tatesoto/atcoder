#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;


ll N, K;
vector<ld> w, p;
bool check(ld x){
    priority_queue<pair<ld, ll>> pq;
    rep(i, N){
        ld over_solt = w.at(i)*(p.at(i) - x);
        pq.push({over_solt, i});
    }
    ld weight = 0;
    ld solt = 0;
    rep(i, K){
        auto pr = pq.top();pq.pop();
        ll index = pr.second;
        weight += w.at(index);
        solt += w.at(index)*p.at(index);
    }
    if(x*weight <= solt) return true;
    else return false;
}


int main() {
    cin>>N>>K;
    w.resize(N), p.resize(N);
    rep(i, N) cin>>w.at(i)>>p.at(i);
    ld right = 100;
    ld left = 0;
    rep(i, 100){
        ld mid = (right + left)/2;
        if(check(mid)) left = mid;
        else right = mid;
    }
    cout<<fixed<<setprecision(16);
    out(left);
}