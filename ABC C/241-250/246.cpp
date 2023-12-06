#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,K,X;
    cin>>N>>K>>X;
    vector<ll> value(N);
    rep(i,N){
        cin>>value.at(i);
    }
    rep(i,N){
        ll d=value.at(i)/X;
        if(K-d<=0){
            value.at(i)-=K*X;
            K=0;
            break;
        }
        else{
            K-=d;
            value.at(i)%=X;
        }
    }
    if(K==0){
        ll sum=0;
        rep(i,N){
            sum+=value.at(i);
        }
        out(sum);
    }
    else{
        sort(all(value));
        reverse(all(value));
        rep(i,N){
            value.at(i)=0;
            K--;
            if(K==0){
                break;
            }
        }
        ll sum=0;
        rep(i,N){
            sum+=value.at(i);
        }
        out(sum);
    }
}