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


int main() {
    ll N;
    cin>>N;
    bitset<60> s(N);
    vector<ll> v;
    ll p=1;
    rep(i,60){
        if(s.test(i)){
            v.push_back(p);
        }
        p*=2;
    }
    ll size=v.size();
    for(ll bit=0;bit<(1<<size);bit++){
        ll sum=0;
        for(ll i=0;i<size;i++){
            if(bit & (1<<i)){
                sum+=v.at(i);
            }
        }
        out(sum);
        //解説(N=4の場合)
        //(1<<i)で0001,0010,0100,1000(i桁目のみが1,それ以外は0)を表す
        //それとbitの&をとると、i桁目のみを残して他の桁はすべて0に
        //よって、bitのi桁目が1なら、i桁目が1で残る
        //逆に、bit1のi桁目が0なら、i桁目が0になる
        //したがって、if(bit & (1<<N))でi桁目が1のときのみ実行する処理を記述できる
    }
}