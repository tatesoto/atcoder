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
#define ld long double

ll N;
vector<pair<ll,ll>> vp(N);
vector<ll> p(N);

bool check(ll S){
    for(ll now=1;now<=N;now++){
        queue<ll> q;
        set<ll> visit;
        q.push(now);
        visit.insert(now);
        while(!q.empty()){
            //queから先頭の要素を頂点として採用
            ll pos=q.front();
            q.pop();
            for(ll i=1;i<=N;i++){
                //posから行ける頂点の内、未確定なもの
                ll z=abs(vp.at(pos).first-vp.at(i).first)+abs(vp.at(pos).second-vp.at(i).second);
                if(p.at(pos)*S>=z&&!visit.count(i)){
                    visit.insert(i);
                    q.push(i);
                }
            }
        }
        if(visit.size()==N){
            return true;
        }
    }
    return false;
}

int main() {
    cin>>N;
    vp.resize(N+1);
    p.resize(N+1);
    for(ll i=1;i<=N;i++){
        ll a,b,c;cin>>a>>b>>c;
        vp.at(i)={a,b};
        p.at(i)=c;
    }
    ll ok=5000000000;
    ll ng=-1;
    while(ok-ng>1){
        ll mid=(ok+ng)/2;
        if(check(mid)) ok=mid;
        else ng=mid;
    }
    out(ok);
}