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
    string S;cin>>S;
    stack<ll> left;
    map<ll,ll> lr;
    set<ll> abc;
    rep(i,S.size()){
        if(S.at(i)=='('){
            left.push(i);
        }
        else if(S.at(i)==')'){
            ll l=left.top();
            left.pop();
            lr[l]=i;
            for(ll j=l+1;j<i;j++){
                if(lr.count(j)){
                    j = lr[j];
                }
                else{
                    abc.erase(S.at(j));
                }
            }
        }
        else{
            if(abc.count(S.at(i))){
                out("No");
                return 0;
            }
            abc.insert(S.at(i));
        }
    }
    out("Yes");
}