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

vector<ll> oper(ll x,ll a){
    vector<ll> res;
    if(x*a<=1000000){
        res.push_back(x*a);
    }
    if(x%10!=0&&x>=10){
        string s=to_string(x);
        string t;
        t+=s.at(s.size()-1);
        s.pop_back();
        t+=s;
        ll y=stol(t);
        if(y<=1000000) res.push_back(y);
    }
    return res;
}

int main() {
    ll a,N;cin>>a>>N;

    queue<ll> q;
    vector<ll> dist(1000000,-1);
    q.push(1);
    dist.at(1)=0;
    while(!q.empty()){
        //queから先頭の要素を頂点として採用
        ll pos=q.front();
        q.pop();
        for(auto x:oper(pos,a)){
            //posから行ける頂点の内、未確定なもの
            if(dist.at(x)==-1){
                dist.at(x)=dist.at(pos)+1;
                q.push(x);
            }
        }
    }
    out(dist.at(N));
}