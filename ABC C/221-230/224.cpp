#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

ll cross(ll ax,ll ay,ll bx,ll by){
    return ax*by-ay*bx;
}

int main() {
    ll N;
    cin>>N;
    vector<ll> x(N),y(N);
    rep(i,N){
        cin>>x.at(i)>>y.at(i);
    }
    ll count=0;
    for(ll i=0;i<N;i++){
        for(ll j=i+1;j<N;j++){
            for(ll k=j+1;k<N;k++){
                ll ax,ay,bx,by;
                ax=x.at(j)-x.at(i);
                ay=y.at(j)-y.at(i);
                bx=x.at(k)-x.at(i);
                by=y.at(k)-y.at(i);
                if(cross(ax,ay,bx,by)!=0){
                    count++;
                }
            }
        }
    }
    out(count);
}