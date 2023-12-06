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
    rep(i,N){
        cin>>a.at(i);
    }
    sort(all(a));
    stack<ll> trash;
    deque<ll> prob;
    set<ll> check;
    rep(i,N){
        ll n=a.at(i);
        if(check.count(n)){
            trash.push(n);
        }
        else{
            check.insert(n);
            prob.push_back(n);
        }
    }
    ll ans=0;
    for(ll i=1; ;i++){
        if(prob.empty()){
            if(trash.size()<=1){
                break;
            }
            else{
                trash.pop();
                trash.pop();
                ans++;
                continue;
            }
        }
        ll x=prob.front();
        if(x==i){
            prob.pop_front();
            ans++;
            continue;
        }
        if(trash.empty()){
            if(prob.size()<=1){
                break;
            }
            else{
                prob.pop_back();
                prob.pop_back();
            }
        }
        else{
            if(trash.size()>=2){
                trash.pop();
                trash.pop();
            }
            else{
                trash.pop();
                if(prob.empty()){
                    break;
                }
                else{
                    prob.pop_back();
                }
            }
        }
        ans++;
    }
    out(ans);
}