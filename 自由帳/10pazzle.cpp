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

const vector<ll> opr={0,1,2,3};
ll calc(ll a,ll b,ll opr_num){
    if(opr_num==0){
        a+=b;
    }
    else if(opr_num==1){
        a-=b;
    }
    else if(opr_num==2){
        a*=b;
    }
    else{

    }
} 

int main() {
    out("左辺の数字の数を入力してください");
    ll N;cin>>N;
    vector<ll> v(N);
    out("左辺の数字を入力してください");
    rep(i,N){
        out(i<<"個目");
        cin>>v.at(i);
    }

}