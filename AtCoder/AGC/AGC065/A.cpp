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
    ll K;cin>>K;
    vector<ll> A(N);
    rep(i, N) cin>>A[i];
    auto solve = [&](vector<ll> v, ll n){
        map<ll, ll> mp;
        rep(i, n) mp[v[i]]++;
        vector<vector<ll>> cnt(n+1);
        for(auto p : mp){
            while(p.second > 0){
                cnt[p.second].push_back(p.first);
                p.second--;
            }
        }
        rep(i, n+1) sort(all(cnt[i]), greater<ll>());
        ll res = 0;
        vector<ll> ret;
        for(int i = n; i >= 3; i--){
            if(cnt[i].size() == 0) continue;
            for(auto x : cnt[i]){
                ret.push_back(x);
            }
            if(cnt[1].empty() || cnt[1].back() == cnt[i].back()) continue;
            ret.push_back(cnt[1].back());
            cnt[1].pop_back();
        }
        vector<ll> tmp;
        vector<ll> rettmp;
        for(auto x : cnt[1]) tmp.push_back(x);
        for(auto x : cnt[2]) tmp.push_back(x);
        sort(all(tmp));
        if(tmp.size() >= 2 && tmp[tmp.size()-1] == tmp[tmp.size()-2]){
            rettmp.push_back(tmp[tmp.size()-1]);
            tmp.pop_back();
        }
        ll prev = 0;
        rep(i, tmp.size()){
            if(i == tmp.size()-1 || tmp[i] == tmp[i+1]){
                for(int j = i; j >= prev; j--){
                    rettmp.push_back(tmp[j]);
                }
                prev = i+1;
            }
        }

        for(auto x : rettmp) ret.push_back(x);
        rep(i, n-1) res += (ret[i+1] - ret[i] + K)%K;
        pair<ll, vector<ll>> p = {res, ret};
        return p;
    };

    auto judge = [&](vector<ll> v, ll n){
        assert(n <= 10);
        sort(all(v));
        ll res = -1;
        vector<ll> ret;
        do{
            ll cnt = 0;
            rep(i, n-1) cnt += (v[i+1] - v[i] + K)%K;
            if(chmax(res, cnt)){
                ret = v;
            }
        }while(next_permutation(all(v)));
        pair<ll, vector<ll>> p = {res, ret};
        return p;
    };

    auto make_test = [&](int i){
        int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
        mt19937_64 rnd(seed + i);
        
        uniform_int_distribution<int> dist_N(4, 10);
        ll n = dist_N(rnd);
        uniform_int_distribution<int> dist_A(1, n);
        vector<ll> A(n);
        for(int i=0; i<n; i++) A[i] = dist_A(rnd) + i;
        sort(all(A));
        return A;
    };

    auto test = [&](int i){
        auto T = make_test(i);
        ll n = T.size();
        cout << n << endl;
        for(int i=0; i< n; i++) cout << T[i] << " \n"[i==n-1];
        auto p = solve(T, n);
        auto q = judge(T, n);
        cout<<p.first<<" expected: "<<q.first<<endl;
        if(p.first != q.first){
            for(auto x : p.second) cout<<x<<" ";
            cout<<endl;
            for(auto x : q.second) cout<<x<<" ";
            cout<<endl;
        }
    };

    // ll K = 1000;
    // rep(i, 10){
    //     out("test " << i);
    //     test(i);
    //     cout<<endl;
    // }

    if(N <= 10){
        auto p = solve(A, N);
        auto q = judge(A, N);
        cout<<p.first<<endl;
        // cout<<" expected: "<<q.first<<endl;
        // if(p.first != q.first){
        //     for(auto x : p.second) cout<<x<<" ";
        //     cout<<endl;
        //     for(auto x : q.second) cout<<x<<" ";
        //     cout<<endl;
        // }
    }
}