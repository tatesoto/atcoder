#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N,Q;cin>>N>>Q;
    vector<ll> a(N);
    rep(i, N) cin>>a.at(i);
    vector<ll> l(Q), r(Q);
    rep(i, Q) cin>>l.at(i)>>r.at(i), l[i]--;

    //クエリのソート
    int sq = max(1, int(N/sqrt(Q)));
    //i回目に何番目のクエリを処理するか
    vector<int> query_index(Q);
    rep(i, Q) query_index.at(i) = i;
    sort(all(query_index), [&](int i, int j) {
        if(l[i]/sq != l[j]/sq) return l[i] < l[j];
        else return r[i] < r[j];
    });

    //クエリ処理
    vector<ll> ans(Q);
    vector<ll> cnt(200005, 0);
    //現在の[l, r)
    ll nl = 0, nr = 0;
    ll ijk_cnt = 0;
    auto add = [&](int i, int d = 1){
        ll x = a.at(i);
        ll &n = cnt.at(x);
        ijk_cnt -= n*(n-1)*(n-2)/6;
        cnt.at(x) += d;
        ijk_cnt += n*(n-1)*(n-2)/6;
    };
    auto del = [&](int i){ add(i, -1);};
    for(int i:query_index){
        //範囲を1つ広げる処理をadd, 狭める処理をdel
        while(nl > l[i]) --nl, add(nl);
        while(nr < r[i]) add(nr), ++nr;
        while(nl < l[i]) del(nl), ++nl;
        while(nr > r[i]) --nr, del(nr);
        //クエリの結果を計算
        ans.at(i) = ijk_cnt; 
    }
    for(auto x:ans) out(x);
}