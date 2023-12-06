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
    string S;cin>>S;
    ll N = S.size();
    stack<char> st;
    set<char> s;
    rep(i, N){
        if(S[i] == '('){
            st.push('(');
        }
        else if(S[i] == ')'){
            while(true){
                auto c = st.top();st.pop();
                if(c == '(') break;
                else s.erase(c);
            }
        }
        else{
            if(s.count(S[i])){
                out("No");
                return 0;
            }
            else{
                st.push(S[i]);
                s.insert(S[i]);
            }
        }
    }
    out("Yes");
}