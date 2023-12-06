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

int main() {
    ll N;
    cin>>N;
    vector<ll> a(N+5),b(N+5);
    for(ll i=2;i<=N;i++){
        cin>>a.at(i);
    }
    for(ll i=3;i<=N;i++){
        cin>>b.at(i);
    }
    vector<ll> dp(N+5);
    dp.at(1)=0;
    dp.at(2)=a.at(2);
    for(ll i=3;i<=N;i++){
        dp.at(i)=min(dp.at(i-1)+a.at(i),dp.at(i-2)+b.at(i));
    }
    ll now=N;
    stack<ll> memo;
    memo.push(N);
    while(now>0){
        if(now==2){
            now-=2;
            memo.push(1);
        }
        else if(now==1){
            now--;
        }
        else if(dp.at(now)-a.at(now)==dp.at(now-1)){
            now--;
            memo.push(now);
        }
        else{
            now-=2;
            memo.push(now);
        }
    }
    ll siz=memo.size();
    out(siz);
    rep(i,siz){
        cout<<memo.top();
        memo.pop();
        if(i<siz-1){
            cout<<" ";
        }
    }
    cout<<endl;
}