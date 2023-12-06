#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll A,B,C,D,E,F,X;
    cin>>A>>B>>C>>D>>E>>F>>X;
    ll lt,la;
    ll a=X%(A+C);
    ll aa=X/(A+C);
    if(a<=A){
        lt=aa*A*B+B*a;
    }
    else{
        lt=aa*A*B+A*B;
    }
    ll b=X%(D+F);
    ll bb=X/(D+F);
    if(b<=D){
        la=bb*D*E+E*b;
    }
    else{
        la=bb*D*E+D*E;
    }
    if(la<lt){
        cout<<"Takahashi"<<endl;
    }
    else if(la>lt){
        cout<<"Aoki"<<endl;
    }
    else{
        cout<<"Draw"<<endl;
    }
}