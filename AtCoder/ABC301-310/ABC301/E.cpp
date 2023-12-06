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
    ll H, W;cin>>H>>W;
    ll T;cin>>T;
    vector<vector<char>> G(H+2, vector<char>(W+2, '#'));
    ll si, sj, gi, gj;
    rep(i, H){
        rep(j, W){
            cin>>G.at(i+1).at(j+1);
            char c = G.at(i+1).at(j+1);
            if(c == 'S'){
                si = i+1;
                sj = j+1;
            }
            else if(c == 'G'){
                gi = i+1;
                gj = j+1;
            }

        }
    }
    queue<pair<ll,ll>> q;
    q.push({si, sj});
    vector<vector<ll>> dist(H+2, vector<ll>(W+2, -1));
    dist.at(si).at(sj) = 0;
    while(!q.empty()){
        auto p = q.front();q.pop();
        ll pi = p.first, pj = p.second;
    }    
}