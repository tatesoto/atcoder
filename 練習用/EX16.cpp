#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> data(5);
    for(int i=0;i<5;i++){
        cin>>data.at(i);
    }
    for(int i=0;i<5;i++){
        if(i==0 && data.at(0)==data.at(1)){
            cout << "YES" <<endl;
            return 0;
        }
        else if(i==4 && data.at(4)==data.at(3)){
            cout << "YES" <<endl;
            return 0;
        }
        else if(i!=0 && i!=4){
            if(data.at(i)==data.at(i-1) || data.at(i)==data.at(i+1)){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}