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

ll H, W;
vector<string> S;
string snuke = "snuke";
const vector<ll> dx = {1, 1, 0, -1, -1, -1, 0, 1};
const vector<ll> dy = {0, 1, 1, 1, 0, -1, -1, -1};
vector<pair<ll,ll>> search(ll x, ll y){
    vector<pair<ll, ll>> ans = {};
    rep(dir, 8){
        bool judge = true;
        rep(i, 5){
            ll nx = x + dx.at(dir)*i;
            ll ny = y + dy.at(dir)*i;
            if(nx < 0 || ny < 0 || nx >= H || ny >= W){
                judge = false;
                break;
            }
            if(S.at(nx).at(ny) != snuke.at(i)){
                judge = false;
                break;
            }
        }
        if(judge){
            rep(i, 5){
                ll nx = x + dx.at(dir)*i;
                ll ny = y + dy.at(dir)*i;
                ans.push_back({nx+1, ny+1});
            }
            break;
        }
    }
    return ans;
}

int main() {
    cin>>H>>W;
    S.resize(H);
    rep(i, H) cin>>S.at(i);
    rep(i, H){
        rep(j, W){
            auto ans = search(i, j);
            if(ans.size() == 5){
                for(auto p:ans){
                    cout<<p.first<<" "<<p.second<<endl;
                }
                return 0;
            }
        }
    }
}