#include <bits/stdc++.h>
using namespace std;
#define ll long long

double d(double ax,double ay,double x,double y){
    double dx,dy;
    dx=(ax-x)*(ax-x);
    dy=(ay-y)*(ay-y);
    return sqrt(dx+dy);
}

int main(){
    ll N,K;
    cin>>N>>K;
    vector<double> light(K);
    for(ll i=0;i<K;i++){
        double x;
        cin>>x;
        light.at(i)=x-1;
    }
    vector<vector<double>> data(N,vector<double>(2));
    for(ll i=0;i<N;i++){
        cin>>data.at(i).at(0)>>data.at(i).at(1);
    }
    double max_d=0;
    for(ll i=0;i<N;i++){
        double mind=pow(10,10);
        for(ll j=0;j<K;j++){
            double tmp;
            tmp=d(data.at(i).at(0),data.at(i).at(1),data.at(light.at(j)).at(0),data.at(light.at(j)).at(1));
            mind=min(mind,tmp);
        }
        max_d=max(mind,max_d);
    }
    cout<<fixed<<setprecision(15);
    cout<<max_d<<endl;
}