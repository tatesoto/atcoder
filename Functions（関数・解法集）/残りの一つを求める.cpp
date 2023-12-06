#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
   ll N;
   cin>>N;
   vector<ll> data(N);
   for(ll i=0;i<N;i++){
    cin>>data.at(i);
   }
   ll ans=0;
   for(ll i=0;i<N;i++){
    ans=ans^data.at(i);
   }
   cout<<ans<<endl;
}