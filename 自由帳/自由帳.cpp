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

int main()  {
    vector<ld> x1 = {5, 4, 5, 2, 5, 4, 7, 6, 8, 3};
    vector<ld> x2 = {7, 8, 6, 5, 6, 7, 6, 4};
    auto avg = [](vector<ld> x) {
        ld sum = 0;
        for (ld i : x) sum += i;
        return sum / x.size();
    };
    auto var = [&](vector<ld> x) {
        ld sum = 0;
        ld a = avg(x);
        for (ld i : x) sum += (i - a) * (i - a);
        return sum / x.size();
    };
    auto t = [&](vector<ld> x1, vector<ld> x2) {
        ld a = avg(x1), b = avg(x2);
        ld c = var(x1), d = var(x2);
        ld e = sqrt(c / x1.size() + d / x2.size());
        return (a - b) / e;
    };
}