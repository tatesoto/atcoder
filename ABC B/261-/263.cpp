#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> family(N+5);
    for(int i=2;i<=N;i++){
        cin>>family.at(i);
    }
    int count=0;
    int x=N;
    while(x!=1){
        x=family.at(x);
        count++;
    }
    cout << count <<endl;
}