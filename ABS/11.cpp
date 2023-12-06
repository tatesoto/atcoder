#include <bits/stdc++.h>
using namespace std;
bool can(int ts,int tg,int sx,int sy,int gx,int gy){
    int d=abs(gx-sx)+abs(gy-sy);
    int dt=tg-ts;
    if(d<=dt && (d+dt)%2==0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int N;
    cin>>N;
    vector<int> time(N);
    vector<int> x(N);
    vector<int> y(N);
    for(int i=0;i<N;i++){
        cin>>time.at(i)>>x.at(i)>>y.at(i);
    }
    bool ans=true;
    if(N>1){
        for(int i=0;i<N-1;i++){
        if(!can(time.at(i),time.at(i+1),x.at(i),y.at(i),x.at(i+1),y.at(i+1))){
            ans=false;
            break;
            }
        }
    }
    if(!can(0,time.at(0),0,0,x.at(0),y.at(0))){
        ans=false;
    }
    if(ans){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}