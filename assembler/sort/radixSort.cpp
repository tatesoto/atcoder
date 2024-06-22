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

void radixSort () {
    vector<ll> bucket(1024, 0);
    vector<ll> sorted(1024, 0);
    for(int i = l; i < r; i++) {
        bucket[(mem[i] >> 6) + 512]++;
    }
    for(int i = 1; i < 1024; i++) {
        bucket[i] += bucket[i-1];
    }
    for(int i = l; i < r; i++) {
        sorted[--bucket[(mem[i] >> 6) + 512]] = mem[i];
    }
    for(int i = l; i < r; i++) {
        mem[i] = sorted[i-l];
    }
}

//l~r-1 -> a[0]~a[1023]
//r~r+1023 -> bucket[0]~bucket[1023]
//r+1024~r+2047 -> sorted[0]~sorted[1023]
int main()  {
    for(int i = l; i < r; i++) {
        mem[i] = (rand() % 65536) - 32768;
    }
    reg[1] = 1;
    reg[1] = reg[1] << 10;
    reg[2] = reg[1];
    reg[2] = reg[2] << 1;
    reg[4] = reg[1];
    reg[3] = 1; //sort flag
    reg[5] = 1; //rsort flag
    reg[2]--;
    reg[6] = mem[reg[4]];
    while(reg[4] < reg[2]) {
        reg[4]++;
        reg[7] = mem[reg[4]];
        reg[6] = reg[7];
        if(reg[3] == 1 && reg[6] > reg[7]) {
            reg[3] = 0;
            if(reg[5] == 0) break;
        }
        else if (reg[5] == 1 && reg[6] < reg[7]) {
            reg[5] = 0;
            if(reg[3] == 0) break;
        }
    }
    reg[2]++;
    if(reg[3] == 1) {
        return 0;
    }
    if(reg[5] == 1) {
        reg[4] = reg[1];
        reg[5] = reg[2];
        reg[5]--;
        while(reg[4] < reg[5]) {
            reg[6] = mem[reg[4]];
            reg[7] = mem[reg[5]];
            mem[reg[4]] = reg[7];
            mem[reg[5]] = reg[6];
            reg[4]++;
            reg[5]--;
        }
        return 0;
    }
    //上位10bitの度数分布.
    //for r4 = l; r4 < r; r4++
    //bucket[(mem[r4] >> 6) + 512 + r]++
    //-512~511 -> 0~1023にスケーリング．
    reg[3] = reg[2];
    reg[3] += reg[1];
    reg[4] = reg[1];
    reg[7] = reg[1];
    reg[7] = reg[7] >> 1;
    reg[7] += reg[2];
    while(reg[4] < reg[2]) {
        reg[5] = mem[reg[4]];
        reg[5] = reg[5] >> 6;
        reg[5] += reg[7];
        reg[6] = mem[reg[5]];
        reg[6]++;
        mem[reg[5]] = reg[6];
        reg[4]++;
    }
    //累積度数分布.
    //for r4 = e; r4 < r+1023; r4++
    reg[3]--;
    reg[4] = reg[2];
    reg[6] = mem[reg[4]];
    while(reg[4] < reg[3]) {
        reg[5] = reg[6];
        reg[4]++;
        reg[6] = mem[reg[4]];
        reg[6] += reg[5];
        mem[reg[4]] = reg[6];
    }
    reg[3]++;
    reg[4] = reg[1];
    //for r4 = l; r4 < r; r4++
    //sorted[--bucket[(mem[r4] >> 6) + 512 + r]] = mem[r4]
    while(reg[4] < reg[2]) {
        reg[5] = mem[reg[4]];
        reg[5] = reg[5] >> 6;
        reg[5] += reg[7];
        reg[6] = mem[reg[5]];
        reg[6]--;
        mem[reg[5]] = reg[6];
        reg[5] = reg[3];
        reg[5] += reg[6];
        reg[6] = mem[reg[4]];
        mem[reg[5]] = reg[6];
        reg[4]++;
    }
    //for r4 = l; r4 < r; r4++
    //memにsortedを挿入ソート．
    reg[4] = reg[1];
    while(reg[4] < reg[2]) {
        reg[5] = mem[reg[3]];
        reg[6] = reg[4];
        while(reg[6] > reg[1]) {
            reg[7] = mem[reg[6]-1];
            if(reg[7] <= reg[5]) break;
            mem[reg[6]] = reg[7];
            reg[6]--;
        }
        mem[reg[6]] = reg[5];
        reg[4]++;
        reg[3]++;
    }
}