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
    ll N, M;cin>>N>>M;
    vector<set<ll>> F(N);
    vector<ll> P(N);
    rep(i, N){
        cin>>P.at(i);
        ll c;cin>>c;
        rep(j, c){
            ll f;cin>>f;
            F.at(i).insert(f);
        }
    }
    rep(i, N){
        rep(j, N){
            bool judge = true;
            if(P.at(i) >= P.at(j)){
                for(auto f:F.at(i)){
                    if(!F.at(j).count(f)){
                        judge = false;
                        break;
                    }
                }
                if(P.at(i) == P.at(j) && F.at(i).size() == F.at(j).size()) judge =  false;
                if(judge){
                    out("Yes");
                    return 0;
                }
            }
        }
    }
    out("No");
}
