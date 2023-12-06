#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string S;
    cin>>S;
    ll N=S.size();
    ll ans=0;
    for(int bit=0;bit<(1<<N-1);bit++){
        ll num=0;
        ll point=0;
        for(int i=0;i<N;i++){
            if(bit & (1<<i)){
                for(ll k=point;k<i;k++){
                    num*=10;
                    num+=S.at(k);
                }

            }
            point=i;
        }
        for(ll k=point;k<N;k++){
            num*=10;
            num+=S.at(k);
        }
        ans+=num;
        num=0;
     }
     cout<<ans<<endl;
}