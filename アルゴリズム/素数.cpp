#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

//素数判定
bool prime_judge(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return n!=1;
}

//約数列挙(※sortなし)
vector<ll> divisor(ll N){
    vector<ll> ans;
    for(ll i=1;i*i<=N;i++){
        if(N%i==0){
            ans.push_back(i);
            if(i!=N/i){
                ans.push_back(N/i);
            }
        }
    }
    return ans;
}

//素因数分解
map<ll,ll> prime_factor(ll N){
    map<ll,ll> ans;
    for(ll i=2;i*i<=N;i++){
        while(N%i==0){
            ans[i]++;
            N/=i;
        }
    }
    if(N!=1){
        ans[N]=1;
    }
    return ans;
}

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
    ll N;
    cin>>N;
    out(prime_judge(N));
    for(ll x:divisor(N)){
        cout<<x<<',';
    }
    cout<<endl;
    for(auto x:prime_factor(N)){
        cout<<x.first<<"^"<<x.second<<"*";
    }
    cout<<endl;

}