#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,K,Q;
    cin>>N>>K>>Q;
    vector<bool> judge(N+5,false);
    vector<int> piece(K+5);
    for(int i=1;i<=K;i++){
        int x;
        cin>>x;
        piece.at(i)=x;
        judge.at(x)=true;
    }
    vector<int> L(Q);
    for(int i=0;i<Q;i++){
        cin>>L.at(i);
    }
    for(int i=0;i<Q;i++){
        int l=L.at(i);
        if(piece.at(l)==N){
            continue;
        }
        if(judge.at(piece.at(l)+1)){
            continue;
        }
        if(judge.at(piece.at(l))){
            judge.at(piece.at(l))=false;
            judge.at(piece.at(l)+1)=true;
            piece.at(l)++;
        }
    }
    for(int i=1;i<=N;i++){
        if(judge.at(i)){
            cout<<i;
        if(i<N){
            cout<<" ";
        }
        }
    }
    cout<<endl;
}