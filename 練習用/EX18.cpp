#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin>> N>> M;
    vector<int> A(M),B(M);
    for(int i=0;i<M;i++){
        cin >> A.at(i) >> B.at(i);
    }
    vector<vector<char>> matrix(N,vector<char>(N,'-'));
    for(int i=0;i<M;i++){
        matrix.at(A.at(i)-1).at(B.at(i)-1)='o';
        matrix.at(B.at(i)-1).at(A.at(i)-1)='x';
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << matrix.at(i).at(j);
            if(j==N-1){
                cout<<endl;
            }
            else{
                cout<<' ';
            }
        }
    }
}