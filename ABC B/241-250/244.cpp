#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    ll n;
    cin>>n;
    string T;
    cin>>T;
    ll X,Y;
    X=0;
    Y=0;
    vector<char> direction{
        {'E','S','W','N'}
    };
    map<char,ll> x,y;
    x['N']=0;
    x['E']=1;
    x['S']=0;
    x['W']=-1;
    y['N']=1;
    y['E']=0;
    y['S']=-1;
    y['W']=0;
    ll directcount=0;
    for(ll i=0;i<n;i++){
        char d=T.at(i);
        if(d=='S'){
            X+=x[direction.at(directcount)];
            Y+=y[direction.at(directcount)];
        }
        if(d=='R'){
            directcount++;
            directcount%=4;
        }
    }
    cout<<X<<" "<<Y<<endl;
}