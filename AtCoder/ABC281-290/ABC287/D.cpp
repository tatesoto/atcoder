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
    string S,T;cin>>S>>T;
    set<ll> match;
    rep(i,T.size()){
        if(S.at(S.size()-1-i) == T.at((T.size()-1-i)) || S.at(S.size()-1-i) == '?' || T.at((T.size()-1-i)) == '?'){
            match.insert(S.size()-1-i);
        }
    }
    if(match.size() == T.size()){
        out("Yes");
    }
    else{
        out("No");
    }
    for(ll i=0;i<T.size();i++){
        match.erase(S.size() - T.size() + i);
        if(S.at(i) == T.at(i) || S.at(i) == '?' || T.at(i) == '?'){
            match.insert(i);
        }
        if(match.size() == T.size()){
            out("Yes");
        }
        else{
            out("No");
        }
    }
}