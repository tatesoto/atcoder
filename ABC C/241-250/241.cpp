#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

ll N;
vector<string> S;

ll rcount(ll i,ll j){
    if(j+5>N-1) return 3;
    else{
        ll c=0;
        rep(k,6){
            if(S.at(i).at(j+k)=='.'){
                c++;
            }
        }
        return c;
    }
}
ll dcount(ll i,ll j){
    if(i+5>N-1) return 3;
    else{
        ll c=0;
        rep(k,6){
            if(S.at(i+k).at(j)=='.'){
                c++;
            }
        }
        return c;
    }
}
ll rdcount(ll i,ll j){
    if(j+5>N-1 || i+5>N-1) return 3;
    else{
        ll c=0;
        rep(k,6){
            if(S.at(i+k).at(j+k)=='.'){
                c++;
            }
        }
        return c;
    }
}
ll rucount(ll i,ll j){
    if(j+5>N-1 || i-5<0) return 3;
    else{
        ll c=0;
        rep(k,6){
            if(S.at(i-k).at(j+k)=='.'){
                c++;
            }
        }
        return c;
    }
}


int main() {
    cin>>N;
    S.resize(N);
    rep(i,N) cin>>S.at(i);
    rep(i,N) rep(j,N){
        if(rcount(i,j)<=2||dcount(i,j)<=2||rdcount(i,j)<=2||rucount(i,j)<=2){
            out("Yes");
            return 0;
        }
    }
    out("No");
}