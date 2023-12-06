#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> high(3);
    for(int i=0;i<3;i++){
        cin >> high.at(i);
    }
    sort(high.begin(),high.end());
    cout<<high.at(2)-high.at(0)<<endl;
}