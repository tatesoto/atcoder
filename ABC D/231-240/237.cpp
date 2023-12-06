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
    deque<ll> dq;
    string S;
    cin>>S;
    dq.push_back(N);
    for(ll i=N-1;i>=0;i--){
        if(S.at(i)=='L'){
            dq.push_back(i);
        }
        else{
            dq.push_front(i);
        }
    }
    rep(i,N+1){
        ll num=dq.front();
        dq.pop_front();
        cout<<num;
        if(i!=N){
            cout<<" ";
        }
    }
    cout<<endl;
}