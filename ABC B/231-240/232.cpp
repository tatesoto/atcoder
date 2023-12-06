#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string S,T;
    cin>>S>>T;
    vector<char> alphabet(26);
    for(ll i=0;i<26;i++){
        alphabet.at(i)='a'+i;
    }
    bool judge=false;
    for(ll K=0;K<26;K++){    
        for(ll i=0;i<S.size();i++){
            char ch=S.at(i);
            if((ch+K)>'z'){
                ch-=26;
            }
            ch+=K;
            if(ch!=T.at(i)){
                break;
            }
            else if(i!=S.size()-1){
                continue;
            }
            else{
                judge=true;
                break;
            }
        }
        if(judge){
            break;
        }
    }
    if(judge){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}