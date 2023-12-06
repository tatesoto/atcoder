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

map<ll,vector<ll>> LR, UD;
ll H,W;

pair<ll,ll> move(pair<ll,ll> bp,char d,ll l){
    ll h=bp.first;
    ll w=bp.second;
    pair<ll,ll> ap;
    if(d=='L'){
        if(LR[h].size()==0){
            ap={h,max(1LL,w-l)};
        }
        else{
            auto iter=lower_bound(all(LR[h]),w);
            if(iter==LR[h].begin()){
                ap={h,max(1LL,w-l)};
            }
            else{
                iter--;
                ll pos=*iter;
                ap={h,max(w-l,pos+1)};
            }
        }
    }
    else if(d=='R'){
        if(LR[h].size()==0){
            ap={h,min(W,w+l)};
        }
        else{
            auto iter=lower_bound(all(LR[h]),w);
            if(iter==LR[h].end()){
                ap={h,min(W,w+l)};
            }
            else{
                ll pos=*iter;
                ap={h,min(w+l,pos-1)};
            }
        }
    }
    else if(d=='U'){
        if(UD[w].size()==0){
            ap={max(1LL,h-l),w};
        }
        else{
            auto iter=lower_bound(all(UD[w]),h);
            if(iter==UD[w].begin()){
                ap={max(1LL,h-l),w};
            }
            else{
                iter--;
                ll pos=*iter;
                ap={max(h-l,pos+1),w};
            }
        }
    }
    else{
        if(UD[w].size()==0){
            ap={min(H,h+l),w};
        }
        else{
            auto iter=lower_bound(all(UD[w]),h);
            if(iter==UD[w].end()){
                ap={min(H,h+l),w};
            }
            else{
                ll pos=*iter;
                ap={min(h+l,pos-1),w};
            }
        }
    }
    return ap;
}

int main() {
    cin>>H>>W;
    ll rs,cs;cin>>rs>>cs;
    ll N;cin>>N;
    rep(i,N){
        ll r,c;cin>>r>>c;
        LR[r].push_back(c);
        UD[c].push_back(r);
    }
    for(auto &p:LR){
        sort(all(p.second));
    }
    for(auto &p:UD){
        sort(all(p.second));
    }
    ll Q;cin>>Q;
    pair<ll,ll> now={rs,cs};
    rep(i,Q){
        char d;ll l;cin>>d>>l;
        now=move(now,d,l);
        cout<<now.first<<" "<<now.second<<endl;
    }
}