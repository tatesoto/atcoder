#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;

int main() {
    ll N;cin>>N;
    string S;cin>>S;
    set<pair<ll, ll>> st;
    st.insert({0, 0});
    pair<ll, ll> now = {0, 0};
    rep(i, N){
        if(S.at(i) == 'R'){
            now.first++;
            st.insert({now});
        }
        if(S.at(i) == 'L'){
            now.first--;
            st.insert({now});
        }
        if(S.at(i) == 'U'){
            now.second++;
            st.insert({now});
        }
        if(S.at(i) == 'D'){
            now.second--;
            st.insert({now});
        }
    }
    if(st.size() == N+1){
        out("No");
    }
    else{
        out("Yes");
    }
}