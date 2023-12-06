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
    int N; cin >> N;
    vector<char> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    //Zアルゴリズム．計算量O(N)
    vector<int> A(N);
    A[0] = N;
    int i = 1, j = 0;
    while(i < N){
        while(i + j < N && S[j] == S[i + j]) j++;
        A[i] = j;
        if(j == 0){
            i++;
            continue;
        }
        int k = 1;
        while(k < j && k + A[k] < j){
            A[i + k] = A[k];
            k++;
        }
        i += k, j -= k;
    }

    for(int i = 1; i < N; i++){
        if(A[i] == N - i){
            cout << N - i << endl;
            return 0;
        }
    }
}
