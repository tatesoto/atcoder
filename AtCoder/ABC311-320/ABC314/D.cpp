#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

int main() {
    ll N;cin>>N;
    string S;cin>>S;
    ll Q;cin>>Q;
    vector<pair<ll,pair<ll,char>>> query(Q);
    rep(i, Q){
        ll t, x;cin>>t>>x;x--;
        char c;cin>>c;
        query.at(i) = {t, {x,c}};
    }
    stack<pair<ll,pair<ll,char>>> st;
    bool judge = false;
    for(int i = Q-1;i>=0;i--){
        auto [t, p] = query.at(i);
        if(t == 1) st.push({t,p});
        else{
            if(judge) continue;
            st.push({t,p});
            judge = true;
        }
    }
    while(!st.empty()){
        auto [t,p] = st.top();st.pop();
        if(t == 1){
            auto [x, c] = p;
            S.at(x) = c;
        }
        else if(t == 2){
            rep(i, S.size()){
                S.at(i) = (char)tolower(S.at(i));
            }
        }
        else{
            rep(i, S.size()){
                S.at(i) = (char)toupper(S.at(i));
            }
        }
    }
    out(S);
}
