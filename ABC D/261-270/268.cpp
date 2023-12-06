#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;

ll Hash(string s){
    ll ans=0;
    ll n=s.size();
    rep(i,n){
        ans*=100;
        ans+=(s.at(i)-'0');
        ans%=mod;
    }
    return ans;
}

int main() {
    ll N,M;cin>>N>>M;
    vector<string> S(N);
    set<ll> T;
    ll length=0;
    rep(i,N){
        cin>>S.at(i);
        length+=S.at(i).size();
    }
    ll plus=16-(length+N-1);
    rep(i,M){
        string t;cin>>t;
        ll x=Hash(t);
        T.insert(x);
    }
    vector<ll> p;
    vector<ll> q;
    rep(i,N){
        p.push_back(i);
    }
    rep(i,N-1){
        q.push_back(0);
    }
    rep(i,plus){
        q.push_back(1);
    }
    do{
        do{
            string x;
            x+=S.at(p.at(0));
            x+="_";
            ll scnt=1;
            rep(i,q.size()){
                if(scnt==N){
                    break;
                }
                if(q.at(i)==0){
                    x+=S.at(p.at(scnt));
                    x+="_";
                    scnt++;
                }
                else{
                    x+="_";
                }
            }
            x.pop_back();
            ll y=Hash(x);
            if(!T.count(y)&&x.size()>=3){
                out(x);
                return 0;
            }
        }
        while(next_permutation(all(q)));
    }
    while(next_permutation(all(p)));
    out("-1");
}