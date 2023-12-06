#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    string S;
    ll K;
    cin>>S>>K;
    vector<char> Sv(S.size());
    vector<vector<char>> sortedSv;
    rep(i,S.size()) Sv.at(i)=S.at(i);
    sort(all(Sv));
    do {
        sortedSv.push_back(Sv);
    }
    while (next_permutation(Sv.begin(), Sv.end()));
    for(auto x:sortedSv.at(K-1)){
        cout<<x;
    }
    cout<<endl;
}