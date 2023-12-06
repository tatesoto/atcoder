#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string S;
    cin>>S;
    if(S.at(0)!=S.at(1)&&S.at(0)!=S.at(2)){
        cout<<S.at(0)<<endl;
        return 0;
    }
    if(S.at(1)!=S.at(0)&&S.at(1)!=S.at(2)){
        cout<<S.at(1)<<endl;
        return 0;
    }
    if(S.at(2)!=S.at(1)&&S.at(2)!=S.at(0)){
        cout<<S.at(2)<<endl;
        return 0;
    }
    else{
        cout<<-1<<endl;
    }
}