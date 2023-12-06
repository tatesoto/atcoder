#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    vector<ll> data(N);
    rep(i,N){
        cin>>data.at(i);
    }
    ll ans=1<<23;
    for(int bit=0;bit<(1<<N);bit++){
        ll t1=0,t2=0,t=0;
        for(int i=0;i<N;i++){
            if(bit & (1<<i)){
                t1+=data.at(i);
            }
            else{
                t2+=data.at(i);
            }
            t=max(t1,t2);
        }
        ans=min(ans,t);
    }
    cout<<ans<<endl;
}