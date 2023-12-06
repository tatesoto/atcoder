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
    ll N, Q;cin>>N>>Q;
    vector<pair<ll,ll>> infant(N);
    vector<set<pair<ll,ll>>> kinder(200000);
    multiset<ll> rate;
    rep(i, N){
        ll a, b;cin>>a>>b;b--;
        infant[i] = {a, b};
        kinder[b].insert({a, i});
    }
    vector<ll> C(Q), D(Q);
    rep(i, Q) cin>>C[i]>>D[i], C[i]--, D[i]--;

    rep(i, 200000){
        if(kinder[i].size() == 0) continue;
        auto p = *kinder[i].rbegin();
        auto highest = p.first;
        rate.insert(highest);
    }

    rep(i, Q){
        ll c = C[i];
        ll d = D[i];
        auto [a, b] = infant[c];

        auto erp = *kinder[b].rbegin();
        auto erphighest = erp.first;
        rate.erase(rate.find(erphighest));
        kinder[b].erase({a, c});

        if(kinder[d].size() != 0){
            auto erq = *kinder[d].rbegin();
            auto erqhighest = erq.first;
            rate.erase(rate.find(erqhighest));
        }
        kinder[d].insert({a, c});
        infant[c] = {a, d};

        if(kinder[b].size() != 0){
            auto inp = *kinder[b].rbegin();
            auto inphighest = inp.first;
            rate.insert(inphighest);
        }

        auto inq = *kinder[d].rbegin();
        auto inqhighest = inq.first;
        rate.insert(inqhighest);

        out(*rate.begin());
    }
}
