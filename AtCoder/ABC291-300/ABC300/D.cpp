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

//エラトステネスの篩
vector<int> Eratosthenes( const int N )
{
    vector<bool> is_prime( N + 1 );
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    vector<int> P;
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}

int main() {
    ll N;cin>>N;
    vector<int> prime = Eratosthenes(10000050);
    map<ll,ll> prime_index;
    rep(i, prime.size()){
        prime_index[prime.at(i)] = i;
    }
    ll ans = 0;
    for(ll p=2;;p++){
        if(p*p*p*p*p > N) break;
        if(!prime_index.count(p)) continue;
        ll idp = prime_index[p];
        for(int j=idp+1;;j++){
            ll q = prime.at(j);
            if(p*p*q*q*q > N) break;
            ll idq = prime_index[q];
            for(int k=idq+1;;k++){
                ll r = prime.at(k);
                if(p*p*q*r*r > N) break;
                ans++;
            }
        }
    }
    out(ans);
}