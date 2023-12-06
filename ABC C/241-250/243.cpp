#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    vector<ll> x(N),y(N);
    rep(i,N) cin>>x.at(i)>>y.at(i);
    string S;
    cin>>S;
    map<ll,ll> lmap,rmap;
    rep(i,N){
        char c=S.at(i);
        if(c=='L'){
            if(!lmap.count(y.at(i))){
                lmap[y.at(i)]=x.at(i);
            }
            else{
                lmap[y.at(i)]=max(lmap[y.at(i)],x.at(i));
            }
        }
        else{
            if(!rmap.count(y.at(i))){
                rmap[y.at(i)]=x.at(i);
            }
            else{
                rmap[y.at(i)]=min(rmap[y.at(i)],x.at(i));
            }
        }
    }
    for(auto p:lmap){
        if(!rmap.count(p.first)){
            continue;
        }
        if(p.second>rmap[p.first]){
            out("Yes");
            return 0;
        }
    }
    out("No");
}