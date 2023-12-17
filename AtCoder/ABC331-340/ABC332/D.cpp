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
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

int main() {
    ll H, W;cin>>H>>W;
    Graph A(H, vector<ll>(W)), B(H, vector<ll>(W));
    rep(i, H)rep(j, W) cin>>A[i][j];
    rep(i, H)rep(j, W) cin>>B[i][j];
    auto equal = [&](vector<ll> rid, vector<ll> cid){
        rep(i, H){
            rep(j, W){
                if(A[i][j] != B[rid[i]][cid[j]]) return false;
            }
        }
        return true;
    };
    vector<ll> rid(H), cid(W);
    iota(all(rid), 0);
    iota(all(cid), 0);
    bool judge = false;
    do{
        do{
            if(equal(rid, cid)){
                judge = true;
                break;
            }
        }while(next_permutation(all(cid)));
        if(judge) break;
    }while(next_permutation(all(rid)));

    if(!judge){
        out(-1);
        return 0;
    }
    auto calc_inversionnumber = [&](vector<ll> v){
        ll res = 0;
        rep(i, v.size()){
            for(int j = i+1; j < v.size(); j++){
                if(v[i] > v[j]) res++;
            }
        }
        return res;
    };
    ll ans = calc_inversionnumber(rid) + calc_inversionnumber(cid);
    out(ans);
}