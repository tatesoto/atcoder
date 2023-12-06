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
    ll H, W;cin>>H>>W;
    ll N;cin>>N;
    map<ll, set<ll>> mp;
    mp[-1].insert(-1);
    mp[H].insert(W);
    rep(i, N){
        ll a, b;cin>>a>>b;a--;b--;
        mp[a].insert(b);
        mp[a].insert(-1);
    }
    ll ans = 0;
    rep(i, H){
        rep(j, W){
            if(mp.count(i)){
                if(mp[i].count(j)){
                    continue;
                }
            }
            ll l = 0;
            ll r = min(H-1, W-1);
            while(r - l > 1){
                ll mid = (l + r)/2;
                bool judge = true;
                auto [key, st] = *mp.lower_bound(i + mid);
                if(key >= i){
                    ll y = *st.lower_bound(j + mid);
                    if(y >= j) judge = false;
                }
                if(judge) l = mid;
                else r = mid;
            }
            ans += l+1;
        }
    }
    out(ans);
}