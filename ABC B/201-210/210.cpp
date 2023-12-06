#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N;
    string S;
    cin>>N>>S;
    rep(i,N){
        if(S.at(i)=='1'){
            if(i%2==0){
                out("Takahashi");
            }
            else{
                out("Aoki");
            }
            return 0;
        }
    }
}