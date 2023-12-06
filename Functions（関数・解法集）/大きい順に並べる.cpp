#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> data={12,50,50,95};
    //このデータを大きい順にならべて、その番号を出力したい。値が同じ時は番号順の速い順
    vector<int> c;
    for(int i=0;i<data.size();i++){
        int x;
        int max_datasize=10;  //datasizeより大きい10の累乗で設定
        x=max_datasize*(100-data.at(i))+i; //100-xで順番反転
        c.push_back(x);
    }
    sort(c.begin(),c.end());
    for(int i=0;i<c.size();i++){
        int max_datasize=10;
        cout<<c.at(i)%max_datasize+1<<endl; //max_datasizeで割れば番号のみ出力される
    }
}