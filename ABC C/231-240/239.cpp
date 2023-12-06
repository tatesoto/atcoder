#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    ll dx=abs(x1-x2),dy=abs(y1-y2);
    set<vector<ll>> d;
    d.insert({6,0});
    d.insert({2,2});
    d.insert({1,5});
    d.insert({5,1});
    d.insert({0,6});
    rep(i,5){
        if(dx+dy<=6 && (dx+dy)%2==0 && !(d.count({dx,dy}))){
            out("Yes");
            return 0;
        }
    }
    out("No");
}