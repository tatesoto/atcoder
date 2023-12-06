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
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    string X;cin>>X;
    //i桁目の総和
    reverse(all(X));
    vector<ll> s(X.size()+2, 0);
    for(int i = X.size(); i > 0;i--){
        int c = X.at(i-1) - '0';
        s.at(i) = s.at(i+1) + c;
    }
    string ans = "";
    for(int i=1;i<=X.size();i++){
        ll x = s.at(i);
        s.at(i) = x%10;
        s.at(i+1) += x/10;
    }
    for(int i=1;i<=X.size();i++){
        char rec = '0' + s.at(i);
        ans.push_back(rec);
    }
    reverse(all(ans));
    if(s.at(X.size()+1) != 0) ans = to_string(s.at(X.size()+1)) + ans;
    out(ans);
}