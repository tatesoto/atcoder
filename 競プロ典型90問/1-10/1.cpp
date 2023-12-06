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

ll N,L,K;
vector<ll> a;
bool judge(ll x){
    ll length=0;
    ll count=0;
    for(ll i=1;i<=N;i++){
        if(a.at(i)-length>=x&&L-a.at(i)>=x){
            count++;
            length=a.at(i);
        }
    }
    if(count>=K){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    cin>>N>>L>>K;
    a.resize(N+1);
    for(ll i=1;i<=N;i++){
        cin>>a.at(i);
    }
    ll left=0;
    ll right=1000000000;
    while(right-left>1){
        ll mid=(left+right)/2;
        if(judge(mid)){
            left=mid;
        }
        else{
            right=mid;
        }
    }
    out(left);
}