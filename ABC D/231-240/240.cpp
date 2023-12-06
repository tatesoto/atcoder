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
    stack<vector<ll>> rec;
    rep(i,N){
        cin>>a.at(i);
    }
    ll num=0;
    rec.push({0,0});
    rep(i,N){
        num++;
        if(a.at(i)==rec.top().at(0)){
            rec.top().at(1)++;
            if(rec.top().at(1)==a.at(i)){
                num-=a.at(i);
                rec.pop();
            }
        }
        else{
            rec.push({a.at(i),1});
        }
        out(num);
    }
}