#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<pair<int,int>> data(N);
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        pair<int,int> c=make_pair(b,a);
        data.at(i)=c;
    }
    sort(data.begin(),data.end());
    for(int i=0;i<N;i++){
        int a,b;
        tie(a,b)=data.at(i);
        cout << b <<" "<<a<<endl;
    }

}