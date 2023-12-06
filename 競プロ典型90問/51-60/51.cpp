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
    int N,K;
    ll P;
    cin>>N>>K>>P;
    vector<ll> A1, A2;
    rep(i, N){
        ll a;cin>>a;
        if(i%2==0) A1.push_back(a);
        else A2.push_back(a);
    }
    int siz1 = A1.size();
    int siz2 = A2.size();
    vector<vector<ll>> B1(siz1+1), B2(siz2+1);
    for(int bit=0;bit<(1<<siz1);bit++){
        ll sum = 0;
        ll cnt = 0;
        for(int i=0;i<siz1;i++){
            if(bit & (1<<i)){
                sum += A1.at(i);
                cnt++;
            }
        }
        B1[cnt].push_back(sum);
    }
    for(int bit=0;bit<(1<<siz2);bit++){
        ll sum = 0;
        ll cnt = 0;
        for(int i=0;i<siz2;i++){
            if(bit & (1<<i)){
                sum += A2.at(i);
                cnt++;
            }
        }
        B2[cnt].push_back(sum);
    }
    rep(i, siz1+1){
        sort(all(B1.at(i)));
    }
    rep(i, siz2+1){
        sort(all(B2.at(i)));
    }
    ll ans = 0;
    for(int i=0;i<=min(K, siz1);i++){
        int j = K - i;
        if(j > siz2) continue;
        ll cnt = 0;
        for(int k=0;k<B1.at(i).size();k++){
            ll diff = P - B1.at(i).at(k);
            cnt += distance(B2.at(j).begin(), upper_bound(all(B2.at(j)), diff));
        }
        ans += cnt;
    }
    out(ans);
}