#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll N,K;
    cin>>N>>K;
    vector<string> S(N);
    rep(i,N) cin>>S.at(i);
    ll ans=0;
    for(int bit=1;bit<(1<<N);bit++){
        map<char,ll> data;
        ll count=0;
        for(int i=0;i<N;i++){
            if(bit & (1<<i)){
                rep(j,S.at(i).size()){
                    char c=S.at(i).at(j);
                    if(data.count(c)){
                        data[c]++;
                    }
                    else{
                        data[c]=1;
                    }
                }
            }
        }
        for(auto p:data){
            if(p.second==K){
                count++;
            }
        }
        ans=max(ans,count);
    }
    out(ans);
}