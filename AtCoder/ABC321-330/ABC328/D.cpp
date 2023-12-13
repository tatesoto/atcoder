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
    string s;cin>>s;
    ll n=s.size();
    string ABC = "ABC";
    ll cnt = 0;
    stack<pair<char, ll>> st;
    rep(i, n){
        char c = s[i];
        if(c == ABC[cnt]){
            cnt++;
            st.push({c, cnt});
            if(cnt == 3){
                rep(j, 3) st.pop();
                if(st.empty()) cnt = 0;
                else cnt = st.top().second;
            }
        }
        else{
            if (c == 'A') cnt = 1;
            else cnt = 0;
            st.push({c, cnt});
        }
    }
    vector<char> ans(st.size());
    for(int i = st.size()-1; i >= 0; i--){
        ans[i] = st.top().first;
        st.pop();
    }
    rep(i, ans.size()) cout << ans[i];
    cout << endl;
}