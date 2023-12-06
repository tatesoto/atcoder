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

ll NtoTen(string s,ll n){
    ll ans=0;
    rep(i,s.size()){
        ll x=s.at(i)-'0';
        ans*=n;
        ans+=x;
    }
    return ans;
}
string TentoN(ll m,ll n){
    string ans;
    while(m>0){
        ll x=m%n;
        char c='0'+x;
        ans=c+ans;
        m/=n;
    }
    return ans;
}

//posのx番目を反転した値を返す
ll onoff(ll pos,ll x,ll y,ll z,ll N){
    string S;
    S=TentoN(pos,2);
    while(S.size()<N){
        S="0"+S;
    }
    if(S.at(N-x)=='0') S.at(N-x)='1';
    else S.at(N-x)='0';
    if(S.at(N-y)=='0') S.at(N-y)='1';
    else S.at(N-y)='0';
    if(S.at(N-z)=='0') S.at(N-z)='1';
    else S.at(N-z)='0';
    ll ans=NtoTen(S,2);
    return ans;
}

int main() {
    ll N,M;cin>>N>>M;
    string S;
    rep(i,N){
        string c;cin>>c;
        S=c+S;
    }
    while(S.size()<N){
        S="0"+S;
    }
    ll start=NtoTen(S,2);
    // グラフ入力受取 (ここでは無向グラフを想定)
    //隣接リスト
    Graph G(pow(2,N));
    for (ll i = 0; i <M; ++i) {
        ll x,y,z;cin>>x>>y>>z;
        for(ll j=0;j<pow(2,N);j++){
            ll a=onoff(j,x,y,z,N);
            G[j].push_back(a);
        }
    }
    queue<ll> q;
    vector<ll> dist(pow(2,N),-1);
    q.push(start);
    dist.at(start)=0;
    while(!q.empty()){
        //queから先頭の要素を頂点として採用
        ll pos=q.front();
        q.pop();
        for(auto x:G.at(pos)){
            //posから行ける頂点の内、未確定なもの
            if(dist.at(x)==-1){
                dist.at(x)=dist.at(pos)+1;
                q.push(x);
            }
        }
    }
    out(dist.at(pow(2,N)-1));
}