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
    ll N;cin>>N;
    vector<ll> a(N);
    rep(i, N) cin>>a.at(i);
    vector<ll> ans;
    ans.push_back(a.at(0));
    ll now = a.at(0);
    rep(i, N-1){
        while(now < a.at(i+1)){
            now++;
            ans.push_back(now);
        }
        while(now > a.at(i+1)){
            now--;
            ans.push_back(now);
        }
    }
    rep(i, ans.size()){
        cout<<ans.at(i)<<" ";
    }
    cout<<endl;
}