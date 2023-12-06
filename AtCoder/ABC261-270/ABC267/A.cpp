#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    string S;
    cin>>S;
    if(S=="Monday"){
        out(5);
    }
    else if(S=="Tuesday"){
        out(4);
    }
    else if(S=="Wednesday"){
        out(3);
    }
    else if(S=="Thursday"){
        out(2);
    }
    else if(S=="Friday"){
        out(1);
    }
}