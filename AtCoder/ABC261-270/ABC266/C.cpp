#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool judge(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3,ll x4,ll y4){
    
    if(((y4-y2)*(x1-x2)+(y2-y1)*(x4-x2))*((y4-y2)*(x3-x2)+(y2-y3)*(x4-x2))<0){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    vector<ll> x(4),y(4);
    for(ll i=0;i<4;i++){
        cin>>x.at(i)>>y.at(i);
    }
    if(judge(x.at(0),y.at(0),x.at(1),y.at(1),x.at(2),y.at(2),x.at(3),y.at(3)) && judge(x.at(1),y.at(1),x.at(2),y.at(2),x.at(3),y.at(3),x.at(0),y.at(0))){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}