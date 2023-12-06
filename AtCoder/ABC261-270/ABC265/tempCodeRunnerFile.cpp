#include <bits/stdc++.h>
using namespace std;

void move(vector<vector<char>> map,vector<vector<bool>> check,int H,int W,int x,int y){
    if(x<=0||y<=0||x>W||y>H){
        cout<<x<<" "<<y<<endl;
        return;
    }
    if(check.at(y).at(x)){
        cout<<-1<<endl;
        return;
    }
    check.at(y).at(x)=true;
    if(map.at(y).at(x)=='U'){
        move(map,check,H,W,x,y+1);
    }
    else if(map.at(y).at(x)=='D'){
        move(map,check,H,W,x,y-1);
    }
    else if(map.at(y).at(x)=='R'){
        move(map,check,H,W,x+1,y);
    }
    else if(map.at(y).at(x)=='L'){
        move(map,check,H,W,x-1,y);
    }
}

int main(){
    int H,W;
    cin>>H,W;
    vector<vector<char>> data(H+1,vector<char>(W+1));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>data.at(i+1).at(j+1);
        }
    }
    vector<vector<bool>> check(H+1,vector<bool>(W+1,false));
    move(data,check,H,W,1,1);
}