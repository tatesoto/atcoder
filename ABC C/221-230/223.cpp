#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    cin>>N;
    vector<double> a(N),b(N);
    rep(i,N){
        cin>>a.at(i)>>b.at(i);
    }
    double sum=0;
    rep(i,N){
        sum+=a.at(i)/b.at(i);
    }
    double time=sum/2;
    double l=0;
    rep(i,N){
        if(time-a.at(i)/b.at(i)>0){
            l+=a.at(i);
            time-=a.at(i)/b.at(i);
        }
        else{
            l+=time*b.at(i);
            break;
        }
    }
    cout<<fixed<<setprecision(10);
    out(l);
}