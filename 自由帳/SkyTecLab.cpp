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

vector<vector<ll>> v;
vector<vector<bool>> check;
void paint(ll x,ll y){
    for(ll i=1;i<=6;i++){
        check.at(i).at(x)=true;
    }
    for(ll j=1;j<=6;j++){
        check.at(x).at(j)=true;
    }
    for(ll i=1;i<=6;i++){
        ll X,Y;
        X=x+i;Y=y+i;
        X%=6;Y%=6;
        X+=1;Y+=1;
        check.at(X).at(Y)=true;
    }
    for(ll i=1;i<=6;i++){
        ll X,Y;
        X=x+i;Y=y-i+6;
        X%=6;Y%=6;
        X+=1;Y+=1;
        check.at(X).at(Y)=true;
    }
}

int main() {
    v.resize(7,vector<ll>(7));
    check.resize(7,vector<bool>(7,false));
    for(ll i=1;i<=6;i++){
        for(ll j=1;j<=6;j++){
            cin>>v.at(i).at(j);
        }
    }
    vector<ll> x={1,2,3,4,5,6};
    vector<ll> y={1,2,3,4,5,6};
    ll ans=0;
    do {
        do{
            ll now=0;
            for(ll i=1;i<=6;i++){
                for(ll j=1;j<=6;j++){
                    check.at(i).at(j)=false;
                }
            }
            rep(i,6){
                if(check.at(x.at(i)).at(y.at(i))){
                    continue;
                }
                paint(x.at(i),y.at(i));
                now+=v.at(x.at(i)).at(y.at(i));
            }
            chmax(ans,now);
        } while(next_permutation(all(x)));
    } while (next_permutation(all(y)));
    out(ans);
}