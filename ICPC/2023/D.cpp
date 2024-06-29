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


ll solve() {
    ll N;cin>>N;
    if(N == 0) return 1;
    string s;cin>>s;
    ll ans = INF;
    for(int i1 = N/7; i1 <= N; i1++) {
        int N1 = N - i1;
        for(int i2 = N1/6; i2 <= min(i1, N1); i2++) {
            int N2 = N1 - i2;
            for(int i3 = N2/5; i3 <= min(i2, N2); i3++) {
                int N3 = N2 - i3;
                for(int i4 = N3/4; i4 <= min(i3, N3); i4++) {
                    int N4 = N3 - i4;
                    for(int i5 = N4/3; i5 <= min(i4, N4); i5++) {
                        int N5 = N4 - i5;
                        for(int i6 = (N5+1)/2; i6 <= min(i5, N5); i6++) {
                            int i7 = N5 - i6;
                            vector<ll> a = {i1, i2, i3, i4, i5, i6, i7};
                            while(a.back() == 0) a.pop_back();
                            ll siz = a.size();
                            vector<int> dp(N+1, false);
                            dp[a[0]] = true;
                            dp[0] = true;
                            for(int i = 1; i < siz; i++) {
                                for(int j = N; j >= 0; j--) {
                                    if(j-a[i] >= 0) dp[j] |= dp[j-a[i]];
                                }
                            }
                            bool judge = true;
                            rep(j, N+1) {
                                if(s[j] == 'o' && !dp[j]) {
                                    judge = false;
                                }
                            }
                            if(judge) {
                                chmin(ans, siz);
                            }
                        }
                    }
                }
            }
        }
    }
    out(ans);
    return 0;
}

int main() {
    while(!solve()) {}
    return 0;
}