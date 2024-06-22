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
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<int>> tests(M);
    vector<char> results(M);
    
    for (int i = 0; i < M; ++i) {
        int Ci;
        cin >> Ci;
        tests[i].resize(Ci);
        for (int j = 0; j < Ci; ++j) {
            cin >> tests[i][j];
            --tests[i][j]; // convert to zero-based index
        }
        cin >> results[i];
    }

    int validCombinations = 0;

    for (int bitmask = 0; bitmask < (1 << N); ++bitmask) {
        bool valid = true;
        
        for (int i = 0; i < M; ++i) {
            int realKeys = 0;
            for (int j = 0; j < tests[i].size(); ++j) {
                if (bitmask & (1 << tests[i][j])) {
                    ++realKeys;
                }
            }
            if ((results[i] == 'o' && realKeys < K) || (results[i] == 'x' && realKeys >= K)) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            ++validCombinations;
        }
    }

    cout << validCombinations << endl;
    return 0;
}
