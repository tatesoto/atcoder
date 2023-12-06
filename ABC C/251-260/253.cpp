#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll Q;
    cin>>Q;
    map<ll,ll> S;
    for(ll i=0;i<Q;i++){
        ll q;
        cin>>q;
        if(q==1){
            ll x;
            cin>>x;
            if(S.count(x)){
                S[x]++;
            }
            else{
                S[x]=1;
            }
        }
        else if(q==2){
            ll x,c;
            cin>>x>>c;
            ll n=min(c,S[x]);
            S[x]-=n;
            if(S[x]==0){
                S.erase(x);
            }
        }
        else{
            auto itr1=S.begin();
            auto itr2=S.end();
            itr2--;
            ll a=itr1->first;
            ll b=itr2->first;
            cout<<b-a<<endl;
        }
    }
}