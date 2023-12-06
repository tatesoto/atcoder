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
    ll M;cin>>M;
    Graph G(9);
    rep(i, M){
        ll a, b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    string start = "888888888"; 
    ll now = 36;
    rep(i, 8){
        ll pos;
        cin >> pos;
        pos--;
        start.at(pos) = '0' + i;
        now -= pos; 
    }
    map<string, ll> permutation;
    string S = "012345678";
    ll cnt = 0;
    do{
        permutation[S] = cnt;
        cnt++;
    } while (next_permutation(all(S)));

    queue<pair<ll, string>> q;
    vector<ll> dist(cnt, -1);
    q.push({now, start});
    dist.at(permutation[start]) = 0;
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        ll pos = p.first;
        string state = p.second; 
        for(auto x: G[pos]){
            string next = state;
            next.at(x) = state.at(pos);
            next.at(pos) = state.at(x);
            if(dist.at(permutation[next]) == -1){
                dist.at(permutation[next]) = dist.at(permutation[state]) + 1;
                q.push({x, next});
            }
        }
    }
    out(dist.at(0));
}