#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string S1,S2;
    cin>>S1>>S2;
    if((S1=="#."&&S2==".#")||(S2=="#."&&S1==".#")){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
}