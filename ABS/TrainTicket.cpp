#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin>>num;
    vector<int> data(4);
    for(int i=0;i<4;i++){
        data.at(3-i)=num%10;
        num/=10;
    }
    for(int tmp=0;tmp<(1<<3);tmp++){
        int sum=data.at(0);
        bitset<3> s(tmp);
        for(int i=0;i<3;i++){
            if(s.test(i)){
                sum+=data.at(i+1);
            }
            else{
                sum-=data.at(i+1);
            }
        }
        if(sum==7){
            cout<<data.at(0);
            for(int i=0;i<3;i++){
                if(s.test(i)){
                    cout<<"+"<<data.at(i+1);
                }
                else{
                    cout<<"-"<<data.at(i+1);
                }
            }
            cout<<"="<<7<<endl;
            return 0;
        }
    }
}