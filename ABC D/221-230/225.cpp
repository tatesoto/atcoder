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
    ll N,Q;cin>>N>>Q;
    vector<pair<ll,ll>> train(N+1,{-1,-1});
    rep(i,Q){
        ll q;cin>>q;
        if(q==1){
            ll x,y;cin>>x>>y;
            train.at(x).second=y;
            train.at(y).first=x;
        }
        else if(q==2){
            ll x,y;cin>>x>>y;
            train.at(x).second=-1;
            train.at(y).first=-1;
        }
        else{
            ll x;cin>>x;
            ll front=train.at(x).first;
            ll back=train.at(x).second;
            deque<ll> ans;
            ans.push_back(x);
            while(front>0){
                ans.push_front(front);
                front=train.at(front).first;
            }
            while(back>0){
                ans.push_back(back);
                back=train.at(back).second;
            }
            ll siz=ans.size();
            cout<<siz<<" ";
            while(!ans.empty()){
                cout<<ans.front();
                ans.pop_front();
                if(!ans.empty()){
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }
}