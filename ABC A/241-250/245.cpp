#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll A,B,C,D;
    cin>>A>>B>>C>>D;
    string ans="Takahashi";
    if(A>C){
        ans="Aoki";
    }
    else if(A==C){
        if(B>D){
            ans="Aoki";
        }
    }
    cout<<ans<<endl;
}