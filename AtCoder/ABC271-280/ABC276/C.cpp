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
    vector<ll> p(N);
    rep(i,N) cin>>p.at(i);
    vector<ll> memo;
    vector<ll> q=p;
    for(ll i=N-1;i>=1;i--){
        memo.push_back(p.at(i));
        if(p.at(i)<p.at(i-1)){
            memo.push_back(p.at(i-1));
            sort(all(memo));
            ll m;
            rep(j,memo.size()){
                if(memo.at(j)==p.at(i-1)){
                    q.at(i-1)=memo.at(j-1);
                    m=memo.at(j-1);
                }
            }
            reverse(all(memo));
            ll cnt=0;
            rep(j,memo.size()){
                if(memo.at(j)==m){
                    continue;
                }
                q.at(i+cnt)=memo.at(j);
                cnt++;
            }
            break;
        }
    }
    rep(i,q.size()){
        cout<<q.at(i);
        if(i<q.size()-1){
            cout<<" ";
        }
    }
    cout<<endl;
}