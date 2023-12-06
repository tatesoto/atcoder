#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,X;
    cin>>N>>X;
    vector<ll> a(N);
    vector<ll> b(N);
    vector<vector<bool>> dp(N+1,vector<bool>(10010,false));
    rep(i,N){
        cin>>a.at(i);
        cin>>b.at(i);
    }
    dp.at(0).at(0)=true;
    rep(i,N){
        rep(j,10005){
            if(dp.at(i).at(j)){
                dp.at(i+1).at(j+a.at(i))=true;
                dp.at(i+1).at(j+b.at(i))=true;
            }
        }
    }
    if(dp.at(N).at(X)){
        out("Yes");
    }
    else{
        out("No");        
    }
}