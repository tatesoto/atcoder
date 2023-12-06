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
    ll N,M;cin>>N>>M;
    vector<set<ll>> to(N), from(N);
    rep(i, M){
        ll x,y;cin>>x>>y;
        x--;y--;
        to[x].insert(y);
        from.at(y).insert(x);
    }
    queue<ll> q;
    rep(i, N){
        if(from.at(i).size() == 0){
            q.push(i);
        }
    }
    ll cnt = 1;
    vector<ll> ans(N);
    while(!q.empty()){
        if(q.size() > 1){
            out("No");
            return 0;
        }
        ll pos = q.front();
        q.pop();
        ans.at(pos) = cnt;
        cnt++;
        for(auto x:to[pos]){
            from.at(x).erase(pos);
            if(from.at(x).size() == 0){
                q.push(x);
            }
        }
    }
    out("Yes");
    rep(i, N){
        cout<<ans.at(i);
        if(i != N-1){
            cout<<" ";
        }
    }
    cout<<endl;
}