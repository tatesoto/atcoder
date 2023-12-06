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
    if(N%2==1){
        return 0;
    }
    ll n=N/2;
    vector<vector<string>> ans(n+1);
    ans.at(0).push_back("");
    for(ll i=1;i<=n;i++){
        for(auto x:ans.at(i-1)){
            ans.at(i).push_back("("+x+")");
        }
        for(ll j=i-1;j>0;j--){
            for(auto x:ans.at(j)){
                for(auto y:ans.at(i-j)){
                    string S;
                    S=x+y;
                    ans.at(i).push_back(S);
                }
            }
        }
        sort(all(ans.at(i)));
        ans.at(i).erase(unique(all(ans.at(i))),ans.at(i).end());
    }
    for(auto x:ans.at(n)){
        out(x);
    }
}