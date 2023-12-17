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
    auto solve = [&](string S){
        string T = S;
        reverse(all(T));
        return T;
    };

    //愚直解かつ正しい解
    auto judge = [&](string S){
        return S;
    };

    //ランダムケース生成
    auto make_string_test = [&](int i, int char_num){
        int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
        mt19937_64 rnd(seed + i);
        
        uniform_int_distribution<int> dist_N(4, 10);
        ll n = dist_N(rnd);
        uniform_int_distribution<int> dist_A(0, char_num-1);
        string S;
        rep(j, n) S.push_back(dist_A(rnd) + 'a');
        return S;
    };

    //テスト
    auto test = [&](int i){
        int char_num = 26;
        auto T = make_string_test(i, char_num);
        cout<<"input"<<endl;
        ll n = T.size();
        cout << n << endl;
        for(int i=0; i< n; i++) cout << T[i] << " \n"[i==n-1];
        auto p = solve(T);
        auto q = judge(T);

        cout<<"output"<<endl;
        out(p);
        if(p != q){
            out("expected: "<<q);
        }
    };
    
    rep(i, 10){
        cout<<"[test"<<i+1<<"]"<<endl;
        test(i);
        cout<<endl;
    }
}