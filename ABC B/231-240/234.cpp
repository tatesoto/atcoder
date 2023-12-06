#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll distance(ll sx,ll sy,ll gx,ll gy){
    ll dx=sx-gx;
    ll dy=sy-gy;
    double d=dx*dx+dy*dy;
    return d;
}

int main(){
    ll N;
    cin>>N;
    vector<ll> x(N),y(N);
    for(ll i=0;i<N;i++){
        cin>>x.at(i)>>y.at(i);
    }
    double maxd=0;
    for(ll i=0;i<N-1;i++){
        for(ll j=i+1;j<N;j++){
            double d=distance(x.at(i),y.at(i),x.at(j),y.at(j));
            maxd=max(maxd,d);
        }
    }
    double ans=sqrt(maxd);
    cout<<fixed<<setprecision(8);
    cout<<ans<<endl;
}