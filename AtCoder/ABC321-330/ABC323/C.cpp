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
    ll N, M;cin>>N>>M;
    vector<ll> A(M);
    rep(i, M) cin>>A[i];
    Grid G(N);
    rep(i, N) cin>>G[i];
    vector<ll> sum(N, 0);
    multiset<ll> st;
    rep(i, N){
        rep(j, M){
            if(G[i][j] == 'o') sum[i] += A[j];
        }
        sum[i] += i + 1;
        st.insert(-sum[i]);
    }
    rep(i, N){
        ll score = sum[i];
        st.erase(st.find(-score));
        ll Mx = -*st.begin();
        priority_queue<ll> pq;
        rep(j, M){
            if(G[i][j] == 'x') pq.push(A[j]);
        }
        ll cnt = 0;
        while(score <= Mx){
            auto x = pq.top();pq.pop();cnt++;
            score += x;
        }
        out(cnt);
        st.insert(-sum[i]);
    }
}