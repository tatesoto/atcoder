#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    string S, T;cin>>S>>T;
    map<char, ll> smp, tmp;
    rep(i, S.size()){
        smp[S.at(i)]++;
        tmp[T.at(i)]++;
    }
    set<ll> change = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
    ll diff = 0;
    rep(i, 26){
        char c = 'a' + i;
        if(change.count(c)){
            diff += abs(smp[c] - tmp[c]);
        }
        else if(smp[c] != tmp[c]){
            out("No");
            return 0;
        }
    }
    ll s = smp['@'] + tmp['@'];
    if(s >= diff){
        out("Yes");
    }
    else{
        out("No");
    }
}