#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string S;
    cin>>S;
    if(S.at(0)==S.at(1) && S.at(0)==S.at(2) && S.at(0)==S.at(3)){
        cout<<"Weak"<<endl;
        return 0;
    }
    for(ll i=0;i<3;i++){
        if(S.at(i+1)-'0'!=(S.at(i)-'0'+1)%10){
            cout<<"Strong"<<endl;
            return 0;
        }
    }
    cout<<"Weak"<<endl;
}