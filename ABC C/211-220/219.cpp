#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    string X;
    ll N;
    cin>>X>>N;
    map<char,char> OtoN,NtoO;
    rep(i,26){
        char a=X.at(i);
        OtoN['a'+i]=a;
        NtoO[a]='a'+i;
    }
    vector<string> neo(N);
    rep(i,N){
        string S;
        cin>>S;
        rep(j,S.size()){
            S.at(j)=NtoO[S.at(j)];
        }
        neo.at(i)=S;
    }
    sort(all(neo));
    rep(i,N){
        string S=neo.at(i);
        rep(j,S.size()){
            S.at(j)=OtoN[S.at(j)];
        }
        out(S);
    }
}