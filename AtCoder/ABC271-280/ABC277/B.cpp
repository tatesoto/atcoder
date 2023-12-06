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
    vector<string> s(N);
    rep(i,N) cin>>s.at(i);
    vector<char> c1,c2;
    c1={'H','D','C','S'};
    c2={'A', '2', '3', '4', '5', '6','7' ,'8' , '9' , 'T', 'J', 'Q', 'K'};
    rep(i,N){
        bool j1=false;
        bool j2=false;
        for(ll j=i+1;j<N;j++){
            if(s.at(i)==s.at(j)){
                out("No");
                return 0;
            }
        }
        string S=s.at(i);
        for(auto x:c1){
            if(S.at(0)==x){
                j1=true;
            }
        }
        for(auto x:c2){
            if(S.at(1)==x){
                j2=true;
            }
        }
        if(!j1||!j2){
            out("No");
            return 0;
        }
    }
    out("Yes");
}