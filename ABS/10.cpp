#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin>>S;
    bool ans=true;
    while(S.size()>0){
        if(S.size()<5){
            ans=false;
            break;
        }
        if(S.size()==5){
            if(S=="dream"){
                ans=true;
                break;
            }
            else if(S=="erase"){
                ans=true;
                break;
            }
            else{
                ans=false;
                break;
            }
        }
        if(S.size()==6){
            if(S=="eraser"){
                ans=true;
                break;
            }
            else{
                ans=false;
                break;
            }
        }
        if(S.size()==7){
            if(S=="dreamer"){
                ans=true;
                break;
            }
            else{
                ans=false;
                break;
            }
        }
        string cutS=S.substr(0,5);
        if(cutS=="dream"){
            if(S.substr(5,5)=="erase"||S.substr(5,5)=="dream"){
                S=S.substr(5);
                continue;
            }
            else if(S.substr(5,7)=="ererase"||S.substr(5,7)=="erdream"){
                S=S.substr(7);
                continue;
            }
            else{
                ans=false;
                break;
            }
        }
        if(cutS=="erase"){
            if(S.substr(5,5)=="erase"||S.substr(5,5)=="dream"){
                S=S.substr(5);
                continue;
            }
            else if(S.substr(5,6)=="rerase"||S.substr(5,6)=="rdream"){
                S=S.substr(6);
                continue;
            }
            else{
                ans=false;
                break;
            }
        }
        else{
            ans=false;
            break;
        }
    }
    if(ans){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}