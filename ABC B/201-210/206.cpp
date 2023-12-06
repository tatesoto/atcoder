#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N; cin>>N;
    for(ll i=1;i<100000;i++){
        if(i*(i+1)/2>=N){
            out(i);
            return 0;
        }
    }
}