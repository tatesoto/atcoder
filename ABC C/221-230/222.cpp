#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

ll rps(ll a,char x,ll b,char y){
    if((x=='G' && y=='C')||(x=='C' && y=='P')||(x=='P'&&y=='G')){
        return a;
    }
    else if(x==y){
        return -1;
    }
    else{
        return b;
    }
}

int main() {
    ll N,M;
    cin>>N>>M;
    vector<string> S(2*N);
    rep(i,2*N) cin>>S.at(i);
    vector<ll> point(2*N);
    rep(i,2*N){
        point.at(i)=99-i;
    }
    rep(i,M){
        rep(j,N){
            ll a1=99-point.at(2*j)%100;
            ll a2=99-point.at(2*j+1)%100;
            ll winner=rps(2*j,S.at(a1).at(i),2*j+1,S.at(a2).at(i));
            if(winner==-1) continue;
            else{
                point.at(winner)+=100;
            }
        }
        sort(all(point));
        reverse(all(point));
    }
    for(auto x:point){
        out(99-x%100+1);
    }
}