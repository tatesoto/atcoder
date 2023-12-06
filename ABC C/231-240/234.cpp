#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll K;
    cin>>K;
    vector<ll> ans;
    while(K>0){
        if(K%2==0){
            ans.push_back(0);
        }
        else{
            ans.push_back(2);
        }
        K/=2;
    }
    reverse(all(ans));
    for(auto x:ans){
        cout<<x;
    }
    cout<<endl;
}