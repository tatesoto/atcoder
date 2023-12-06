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
    ll N, Q;cin>>N>>Q;
    vector<priority_queue<ll, vector<ll>, greater<ll>>> box(N+1);
    vector<set<ll>> index(200010);
    rep(q, Q){
        ll c;cin>>c;
        if(c == 1){
            ll i, j;cin>>i>>j;
            box.at(j).push(i);
            index.at(i).insert(j);
        }
        else if(c == 2){
            ll i;cin>>i;
            priority_queue<ll, vector<ll>, greater<ll>> pq;
            ll siz = box.at(i).size();
            rep(k, siz){
                ll x = box.at(i).top();box.at(i).pop();
                cout<<x;
                if(k != siz-1) cout<<" ";
                pq.push(x);
            }
            cout<<endl;
            box.at(i) = pq;
        }
        else{
            ll i;cin>>i;
            ll ed = *index.at(i).rbegin();
            for(auto x:index.at(i)){
                cout<<x;
                if(x != ed) cout<<" ";
            }
            cout<<endl;
        }
    }
}