#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,M;
    cin>>N>>M;
    vector<ll> A(N),B(M);
    rep(i,N) cin>>A.at(i);
    rep(i,M) cin>>B.at(i);
    sort(all(B));
    ll ans=1<<30;
    rep(i,N){
        auto iter=lower_bound(all(B),A.at(i));
        ll n=iter-B.begin();
        if(n==0){
            ans=min(ans,abs(A.at(i)-B.at(0)));
        }
        else if(n==B.size()){
            ans=min(ans,abs(A.at(i)-B.at(n-1)));
        }
        else
        ans=min(ans,min(abs(A.at(i)-B.at(n)),abs(A.at(i)-B.at(n-1))));
    }
    out(ans);
}