#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,Q;
    cin>>N>>Q;
    vector<ll> swap(Q);
    rep(i,Q) cin>>swap.at(i);
    map<ll,ll> ans;
    rep(i,N) ans[i+1]=i;
    vector<ll> arry;
    rep(i,N) arry.push_back(i+1);
    rep(i,Q){
        ll fromball=swap.at(i);
        ll place=ans[fromball];
        if(place!=N-1){
            ll toball=arry.at(place+1);
            ll tmp=arry.at(place);
            arry.at(place)=arry.at(place+1);
            arry.at(place+1)=tmp;
            ll t=ans[fromball];
            ans[fromball]=ans[toball];
            ans[toball]=t;
        }
        else{
            ll toball=arry.at(place-1);
            ll tmp=arry.at(place);
            arry.at(place)=arry.at(place-1);
            arry.at(place-1)=tmp;
            ll t=ans[fromball];
            ans[fromball]=ans[toball];
            ans[toball]=t;
        }
    }
    for(ll i=0;i<N;i++){
        cout<<arry.at(i);
        if(i!=N-1){
            cout<<" ";
        }
    }
    cout<<endl;
}