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
    ll N,S;cin>>N>>S;
    vector<ll> a(N+1),b(N+1);
    for(ll i=1;i<=N;i++){
        cin>>a.at(i)>>b.at(i);
    }
    vector<vector<bool>> dp(N+1,vector<bool>(S+200,false));
    dp.at(0).at(0)=true;
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<=S;j++){
            if(dp.at(i-1).at(j)){
                dp.at(i).at(j+a.at(i))=true;
                dp.at(i).at(j+b.at(i))=true;
            }
        }
    }
    if(!dp.at(N).at(S)){
        out("No");
    }
    else{
        out("Yes");
        string ans;
        ll now=S;
        for(ll i=N;i>=1;i--){
            if(now-a.at(i)>=0&&dp.at(i-1).at(now-a.at(i))){
                ans+="H";
                now-=a.at(i);
            }
            else{
                ans+="T";
                now-=b.at(i);
            }
        }
        reverse(all(ans));
        out(ans);
    }
}