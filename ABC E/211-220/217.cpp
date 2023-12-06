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
    ll Q;cin>>Q;
    queue<ll> q;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i, Q){
        ll c;cin>>c;
        if(c == 1){
            ll x;cin>>x;
            q.push(x);
        }
        else if(c == 2){
            if(!pq.empty()){
                ll x = pq.top();pq.pop();
                out(x);
            }
            else{
                ll x = q.front();q.pop();
                out(x);
            }
        }
        else{
            while(!q.empty()){
                pq.push(q.front());q.pop();
            }
        }
    }
}