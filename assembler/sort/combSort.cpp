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

vector<ll> mem(4096);
vector<ll> reg(8, 0);
#define NUM_MAX 65536
#define l 1024
#define r 2048

void combSort () {
    int gap = r-l;
    bool swapped = true;
    while(gap != 1 || swapped) {
        gap = (gap >> 1) + (gap >> 2) + (gap >> 6); //gap = gap * 0.765625 ≒ gap / 1.3
        if(gap < 1) gap = 1;
        swapped = false;
        for(int i = l; i < r-gap; i++) {
            if(mem[i] > mem[i+gap]) {
                swap(mem[i], mem[i+gap]);
                swapped = true;
            }
        }
    }
}