#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

vector<ll> adult;
vector<ll> child;

// index が条件を満たすかどうか
bool isOK1(int index, int key) {
    if (adult[index] >= key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search1(int key) {
    int ng = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = (int)adult.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK1(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

bool isOK2(int index, int key) {
    if (child[index] < key) return true;
    else return false;
}

// 汎用的な二分探索のテンプレ
int binary_search2(int key) {
    int ng = (int)child.size(); //「index = 0」が条件を満たすこともあるので、初期値は -1
    int ok = -1; // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* ok と ng のどちらが大きいかわからないことを考慮 */
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;

        if (isOK2(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ll N;
    string S;
    cin>>N>>S;
    bool judge1=false,judge2=false;
    for(ll i=0;i<N;i++){
        ll x;
        cin>>x;
        if(S.at(i)=='1'){
            adult.push_back(x);
            judge1=true;
        }
        else{
            child.push_back(x);
            judge2=true;
        }
    }
    if(!judge1||!judge2){
        cout<<S.size()<<endl;
        return 0;
    }
    sort(all(adult));
    sort(all(child));
    ll ans=0;
    for(auto x:adult){
        ll sum;
        sum=adult.size()-binary_search1(x)+binary_search2(x)+1;
        ans=max(ans,sum);
    }
    for(auto y:child){
        ll sum;
        sum=adult.size()-binary_search1(y)+binary_search2(y)+1;
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
}