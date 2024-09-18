#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

ll countOddOnesSubarrays(const string &A) {
    ll N = A.length();
    vector<ll> prefixSum(N + 1, 0); // 累積和を保存するベクター
    unordered_map<ll, ll> countEvenOdd; // 奇偶の出現回数を記録するハッシュマップ
    countEvenOdd[0] = 1; // 初期値：累積和が0で偶数としてカウント

    ll oddOnesCount = 0;
    
    for (ll i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + (A[i] == '1' ? 1 : 0);
        ll oddOrEven = prefixSum[i + 1] % 2;
        if (oddOrEven == 1) {
            // 奇数の累積和の場合、その前に出現した偶数の累積和の数だけ奇数個の1を含む部分列がある
            oddOnesCount += countEvenOdd[0];
        } else {
            // 偶数の累積和の場合、その前に出現した奇数の累積和の数だけ奇数個の1を含む部分列がある
            oddOnesCount += countEvenOdd[1];
        }
        // 現在の累積和の奇偶をカウント
        countEvenOdd[oddOrEven]++;
    }

    ll OnesCount = 0;
    for (ll i = 0; i < N; ++i) {
        if (A[i] == '1') {
            OnesCount++;
        }
    }

    oddOnesCount -= OnesCount;
    
    return oddOnesCount;
}

int main() {
    ll N;cin>>N;
    vector<string> A(30);
    rep(i, N) {
        ll a;cin>>a;
        ll now = 1;
        rep(j, 30) {
            if(a & now) {
                A[j].push_back('1');
            } else {
                A[j].push_back('0');
            }
            now *= 2;
        }
    }
    ll ans = 0;
    ll now = 1;
    rep(i, 30) {
        ll x = countOddOnesSubarrays(A[i]);
        ans += x * now;
        now *= 2;
    }
    out(ans);
}

// ll solve(vector<ll> testcase){
//     ll N = testcase.size();
//     vector<string> A(30);
//     rep(i, N) {
//         ll a = testcase[i];
//         ll now = 1;
//         rep(j, 30) {
//             if(a & now) {
//                 A[j].push_back('1');
//             } else {
//                 A[j].push_back('0');
//             }
//             now *= 2;
//         }
//     }
//     ll ans = 0;
//     ll now = 1;
//     rep(i, 30) {
//         ll x = countOddOnesSubarrays(A[i]);
//         ans += x * now;
//         now *= 2;
//     }
//     assert(ans >= 0);
//     return ans;
// }

// int main() {
//     ll t = 1000;
//     vector<vector<ll>> test(t);
//     auto make_array_test = [&](int i){
//         int seed = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();
//         mt19937 rnd(seed + i);
//         uniform_int_distribution<int> dist_N(1, 100);
//         ll n = dist_N(rnd);
//         vector<ll> A(n);
//         rep(j, n) {
//             uniform_int_distribution<int> dist_A(0, 100000000);
//             A[j] = dist_A(rnd);
//         }
//         return A;
//     };
//     rep(i, t) {
//         test[i] = make_array_test(i);
//     }
//     auto naive = [&](vector<ll> A){
//         ll N = A.size();
//         ll res = 0;
//         rep(i, N-1) {
//             for(int j = i+1; j < N; j++) {
//                 ll tmp = 0;
//                 for(int k = i; k <= j; k++) {
//                     tmp ^= A[k];
//                 }
//                 res += tmp;
//             }
//         }
//         return res;
//     };
//     rep(i, t) {
//         out("test" + to_string(i));
//         ll x = solve(test[i]);
//         ll y = naive(test[i]);
//         if(x != y) {
//             out("WA");
//             out(test[i].size());
//             for (int i = 0; i < int(test[i].size()); i++) {
//                 cout << test[i][i] << " ";
//                 if(i == int(test[i].size()) - 1) cout << endl;
//             }
//             cout << "expected: " << y << endl;
//             cout << "got: " << x << endl;
//             return 0;
//         }
//     }
//     out("AC");
// }