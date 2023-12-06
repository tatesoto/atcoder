#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,A,X,Y;
    cin>>N>>A>>X>>Y;
    ll sum=0;
    rep(i,N){
        if(i>=A){
            sum+=Y;
        }
        else{
            sum+=X;
        }
    }
    out(sum);
}