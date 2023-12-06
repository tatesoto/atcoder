#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    vector<ll> a;
    ll zerocount=0;
    while(N>0){
        ll n=N%10;
        if(n==0){
            zerocount++;
        }
        else{
            a.push_back(n);
        }
        N/=10;
    }
    sort(all(a),greater<ll>());

    ll ans=0;
    for(int bit=1;bit<(1<<a.size());bit++){
        ll sum1=0;
        ll sum2=0;
        for(int i=0;i<a.size();i++){
            if(bit & (1<<i)){
                sum1*=10;
                sum1+=a.at(i);
            }
            else{
                sum2*=10;
                sum2+=a.at(i);
            }
        }
        ans=max(ans,sum1*sum2);
    }
    ans*=pow(10,zerocount);
    out(ans);
}