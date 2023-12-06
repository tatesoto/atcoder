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
    if(S.size()!=8){
        out("No");
        return 0;
    }
    if(S.at(0)>='A'&&S.at(0)<='Z'){
        for(ll i=1;i<=6;i++){
            if(i==1&&S.at(i)=='0'){
                out("No");
                return 0;
            }
            else if(S.at(i)>='0'&&S.at(i)<='9'){
            }
            else{
                out("No");
                return 0;
            }
        }
        if(S.at(7)>='A'&&S.at(7)<='Z'){

        }
        else{
            out("No");
            return 0;
        }
    }
    else{
        out("No");
        return 0;
    }
    out("Yes");
    return 0;
}