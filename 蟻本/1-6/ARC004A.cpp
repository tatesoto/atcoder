#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll d_sq(ll x1,ll y1,ll x2,ll y2){
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main() {
    ll N;
    cin>>N;
    vector<ll> x(N);
    vector<ll> y(N);
    for(ll i=0;i<N;i++){
        cin>>x.at(i)>>y.at(i);
    }
    ll maxd=0;
    for(ll i=0;i<N-1;i++){
        for(ll j=i+1;j<N;j++){
            maxd=max(maxd,d_sq(x.at(i),y.at(i),x.at(j),y.at(j)));
        }
    }
    double ans=sqrt(maxd);
    cout<<ans<<endl;
}