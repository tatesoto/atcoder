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
    ll H,W,N;cin>>H>>W>>N;
    ll h,w;cin>>h>>w;
    Graph a(H,vector<ll>(W));
    rep(i,H){
        rep(j,W){
            cin>>a.at(i).at(j);
        }
    }
    map<ll,ll> kind;
    rep(i,H){
        rep(j,W){
            if(i<h && j<w) continue;
            kind[a.at(i).at(j)]++;
        }
    }
    rep(i,H-h+1){
        rep(j,W-w+1){
            cout<<kind.size();
            if(i == H-h && j == W-w){
                cout<<endl;
                break;
            }
            if(j < W-w){
                cout<<" ";
                for(ll k=i;k<i+h;k++){
                    kind[a.at(k).at(j+w)]--;
                    if(kind[a.at(k).at(j+w)]==0){
                        kind.erase(a.at(k).at(j+w));
                    }
                }
                for(ll k=i;k<i+h;k++){
                    kind[a.at(k).at(j)]++;
                }
            }
            else{
                cout<<endl;
                kind.clear();
                rep(k,H){
                    rep(l,W){
                        if(i<k && k<=i+h && l<w) continue;
                        kind[a.at(k).at(l)]++;
                    }
                }
            }
        }
    }
}