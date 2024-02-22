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
    vector<ll> t(N), x(N);
    rep(i, N) cin>>t[i]>>x[i];
    map<ll, ll> mp;
    rep(i, N){
        if(t[i] == 1){
            mp[x[i]]++;
        }
        else{
            if(mp.find(x[i]) != mp.end()){
                mp[x[i]]--;
                if(mp[x[i]] == 0) mp.erase(x[i]);
            }
            else{
                out(-1);
                return 0;
            }
        }
    }
    ll ansk = -1;
    ll k = 0;
    vector<ll> ans;
    map<ll,ll> enemy;
    for(int i = N-1; i >= 0; i--){
        if(t[i] == 1){
            if(enemy.find(x[i]) != enemy.end()){
                ans.push_back(1);
                enemy[x[i]]--;
                if(enemy[x[i]] == 0) enemy.erase(x[i]);
                k--;
            }
            else{
                ans.push_back(0);
            }
        }
        else{
            enemy[x[i]]++;
            k++;
        }
        chmax(ansk, k);
    }
    out(ansk);
    reverse(all(ans));
    for(auto x: ans){
        out(x);
    }
}