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

int main() {
    ll N;cin>>N;
    string S;cin>>S;
    stack<ll> st;
    string ans = "";
    ll cnt = 0;
    rep(i, N){
        if(S.at(i) == ')' && cnt > 0){
            while(true){
                char c = st.top();st.pop();
                if(c == '('){
                    cnt--;
                    break;
                }
            }
        }
        else{
            st.push(S.at(i));
            if(S.at(i) == '(') cnt++;
        }
    }
    while(!st.empty()){
        auto c = st.top();st.pop();
        ans.push_back(c);
    }
    reverse(all(ans));
    out(ans);
}