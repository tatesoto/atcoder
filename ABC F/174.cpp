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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int N,Q;cin>>N>>Q;
    vector<int> c(N);
    rep(i, N) cin>>c.at(i);
    vector<int> l(Q), r(Q);
    rep(i, Q) cin>>l.at(i)>>r.at(i), l.at(i)--;

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
    vector<int> color(N+1, 0);
    int now = 0;
    vector<int> ans(Q);
    //範囲をiへ1つ広げる処理をadd, 狭める処理をdel
    auto add = [&](int i, int d = 1){
        //addの処理
        int x = c.at(i);
        color.at(x) += d;
        if(color.at(x) == (1+d)/2) now += d;
    };
    auto del = [&](int i){ add(i, -1);};
    
    //現在の[l, r)
    int nl = 0, nr = 0;
    for(int i:query_index){
        while(nl > l[i]) --nl, add(nl);
        while(nr < r[i]) add(nr), ++nr;
        while(nl < l[i]) del(nl), ++nl;
        while(nr > r[i]) --nr, del(nr);
        //クエリの結果を計算
        ans.at(i) = now;
    }
    for(auto x:ans) out(x);
}