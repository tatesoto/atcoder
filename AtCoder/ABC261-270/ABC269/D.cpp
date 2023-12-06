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

const vector<ll> dx={-1,-1,0,0,1,1};
const vector<ll> dy={-1,0,-1,1,0,1};

vector<vector<bool>> check,seen;

void dfs(ll i,ll j) {
    seen.at(i).at(j) = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    rep(dir,6){ 
        ll nh=i+dx.at(dir);
        ll nw=j+dy.at(dir);
        if(seen.at(nh).at(nw)||!check.at(i).at(j)) continue;
        dfs(nh, nw); // 再帰的に探索
    }
}

int main() {
    ll N;
    cin>>N;
    seen.resize(3100,vector<bool>(3100));
    check.resize(3100,vector<bool>(3100));
    vector<ll> x(N),y(N);
    rep(i,N){
        ll inx,iny;
        cin>>inx>>iny;
        x.at(i)=inx+1500;
        y.at(i)=iny+1500;
        check.at(x.at(i)).at(y.at(i))=true;
    }
    ll count=0;
    rep(i,N){
        if(seen.at(x.at(i)).at(y.at(i))) continue;
        else{
            dfs(x.at(i),y.at(i));
            count++;
        }
    }
    out(count);
}