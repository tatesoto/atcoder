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

ll xy_to_x(ll x,ll y){
    ll ans=0;
    x+=300;
    y+=300;
    if(x<0||x>600||y<0||y>600){
        return -1;
    }
    ans=y*601+x;
    return ans;
}

pair<ll,ll> x_to_xy(ll x){
    pair<ll,ll> p;
    p=make_pair(x%601-300,x/601-300);
    return p;
}

const vector<ll> dx={-2,-2,-1,-1,1,1,2,2};
const vector<ll> dy={-1,1,-2,2,-2,2,-1,1};

int main() {
    ll x,y;cin>>x>>y;
    queue<ll> q;
    vector<ll> dist(601*601,-1);
    q.push(xy_to_x(0,0));
    dist.at(xy_to_x(0,0))=0;
    while(!q.empty()){
        ll pos=q.front();
        q.pop();
        for(ll dir=0;dir<8;dir++){
            ll nx=x_to_xy(pos).first+dx.at(dir);
            ll ny=x_to_xy(pos).second+dy.at(dir);
            ll next=xy_to_x(nx,ny);
            if(next==-1) continue;
            if(dist.at(next)==-1){
                dist.at(next)=dist.at(pos)+1;
                q.push(next);
            }
        }
    }
    out(dist.at(xy_to_x(x,y)));
}