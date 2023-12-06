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

ll cnt;
vector<string> S;
bool check(ll x){
    if(x<0||x>=9){
        return false;
    }
    else{
        return true;
    }
}
void judge(ll i1,ll j1,ll i2,ll j2){
    ll di=i2-i1;
    ll dj=j2-j1;
    if(check(i1-dj)&&check(j1+di)&&check(i1+di-dj)&&check(j1+di+dj)&&S.at(i1-dj).at(j1+di)=='#'&&S.at(i1+di-dj).at(j1+di+dj)=='#'){
        cnt++;
    }
    return;
}

int main() {
    S.resize(9);
    cnt=0;
    rep(i,9) cin>>S.at(i);
    rep(i,9){
        rep(j,9){
            if(S.at(i).at(j)=='#'){
                for(ll k=i+1;k<9;k++){
                    for(ll l=j;l<9;l++){
                        if(S.at(k).at(l)=='#'){
                            judge(i,j,k,l);
                        }
                    }
                }
            }
        }
    }
    out(cnt);
}