#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,M;
    cin>>N>>M;
    set<string> data;
    vector<string> j(N);
    rep(i,N){
        cin>>j.at(i);
    }
    rep(i,M){
        string x;
        cin>>x;
        data.insert(x);
    }
    rep(i,N){
        if(data.count(j.at(i))){
            out("Yes");
        }
        else{
            out("No");
        }
    }
}