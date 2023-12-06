#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,A,B,P,Q,R,S;
    cin>>N>>A>>B>>P>>Q>>R>>S;
    for(ll i=P;i<=Q;i++){
        for(ll j=R;j<=S;j++){
            if(abs(i-A)==abs(j-B)){
                cout<<'#';
            }
            else{
                cout<<'.';
            }
        }
        cout<<endl;
    }
}