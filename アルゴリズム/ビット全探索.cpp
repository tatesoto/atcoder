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

//a(0)~a(N-1)の何個かを選んで総和をKとできるかのプログラム

int main(){
    int N,K;
    cin>>N>>K;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A.at(i);
    }

    //bit全探索
    bool ans=false;
    for(int bit=0;bit<(1<<N);bit++){
        ll sum=0;

        for(int i=0;i<N;i++){
            if(bit & (1<<i)){
                sum+=A.at(i);
            }
        }
        //解説(N=4の場合)
        //(1<<i)で0001,0010,0100,1000(i桁目のみが1,それ以外は0)を表す
        //それとbitの&をとると、i桁目のみを残して他の桁はすべて0に
        //よって、bitのi桁目が1なら、i桁目が1で残る
        //逆に、bit1のi桁目が0なら、i桁目が0になる
        //したがって、if(bit & (1<<N))でi桁目が1のときのみ実行する処理を記述できる



        //判定
        if(sum==K){
            ans=true;
        }
    }
    if(ans){
        cout <<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}