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

int main() {
    ll N;cin>>N;
    vector<ll> a(N);
    stack<pair<ll,ll>> ans;
    rep(i,N) cin>>a.at(i);
    rep(i,N){
        while(!ans.empty()){
            if(ans.top().first>a.at(i)){
                break;
            }
            ans.pop();
        }
        if(ans.empty()){
            cout<<-1;
        }
        else{
            cout<<ans.top().second;
        }
        if(i!=N-1){
            cout<<" ";
        }
        ans.push({a.at(i),i+1});
    }
    cout<<endl;
}