#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)

ll N;
vector<vector<bool>> s(200,vector<bool>(200,false)),t(200,vector<bool>(200,false));

bool judgef(vector<vector<bool>> S){
    ll iS,jS,it,jt;
    bool judge=false;
    rep(i,200){
        rep(j,200){
            if(S.at(i).at(j)){
                iS=i;
                jS=j;
                judge=true;
                break;
            }
        }
        if(judge) break;
    }
    judge=false;
    rep(i,200){
        rep(j,200){
            if(t.at(i).at(j)){
                it=i;
                jt=j;
                judge=true;
                break;
            }
        }
        if(judge) break;
    }
    ll di=it-iS;
    ll dj=jt-jS;
    rep(i,200){
        rep(j,200){
            if(S.at(i).at(j)){
                if(i+di<0||j+dj<0||i+di>=200||j+dj>=200){
                    return false;
                }
                if(!t.at(i+di).at(j+dj)){
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    cin>>N;
    ll cs=0,ct=0;
    rep(i,N) rep(j,N){
        char x; cin>>x;
        if(x=='#'){
            s.at(i).at(j)=true;
            cs++;
        }
    }
    rep(i,N) rep(j,N){
        char x; cin>>x;
        if(x=='#'){
            t.at(i).at(j)=true;
            ct++;
        }
    }
    if(cs!=ct){
        out("No");
        return 0;
    }
    vector<vector<bool>> s1(200,vector<bool>(200,false)),s2(200,vector<bool>(200,false)),s3(200,vector<bool>(200,false));
    rep(i,N) rep(j,N){
        if(s.at(i).at(j)){
            s1.at(j).at(N-1-i)=true;
        }
    }
    rep(i,N) rep(j,N){
        if(s.at(i).at(j)){
            s2.at(N-1-i).at(N-1-j)=true;
        }
    }
    rep(i,N) rep(j,N){
        if(s.at(i).at(j)){
            s3.at(N-1-j).at(i)=true;
        }
    }
    if(judgef(s)||judgef(s1)||judgef(s2)||judgef(s3)){
        out("Yes");
    }
    else{
        out("No");
    }
}