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

int main() {
    ll N,K;cin>>N>>K;
    vector<ll> a(N);
    rep(i, N) cin>>a.at(i);
    ll left = 0, right = 0;
    ll ans = 0;
    map<ll, ll> mp;
    set<ll> st;
    while(right < N){
        if(st.size()<K){
            st.insert(a.at(right));
            mp[a.at(right)]++;
            chmax(ans, right-left+1);
            right++;
        }
        else{
            if(st.count(a.at(right))){
                mp[a.at(right)]++;
                chmax(ans, right-left+1);
                right++;
            }
            else{
                mp[a.at(left)]--;
                if(mp[a.at(left)] == 0) st.erase(a.at(left));
                left++;
            }
        }
    }
    out(ans);
}