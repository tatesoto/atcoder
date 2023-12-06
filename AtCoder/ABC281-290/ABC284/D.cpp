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

//素因数分解
map<ll,ll> prime_factor(ll N){
    map<ll,ll> ans;
    bool judge=false;
    for(ll i=2;i*i<=N;i++){
        while(N%i==0){
            ans[i]++;
            N/=i;
            judge=true;
        }
        if(judge){
            if(ans[i]==2){
                ans[N]++;
                break;
            }
            else if(ans[i]==1){
                ans[sqrt(N)]=2;
                break;
            }
        }
    }
    return ans;
}

int main() {
    ll T;cin>>T;
    rep(i,T){
        ll N;cin>>N;
        map<ll,ll> mp=prime_factor(N);
        ll p,q;
        for(auto x:mp){
            if(x.second==2){
                p=x.first;
            }
            else{
                q=x.first;
            }
        }
        cout<<p<<" "<<q<<endl;
    }
}