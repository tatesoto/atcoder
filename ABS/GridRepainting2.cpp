#include <bits/stdc++.h>
using namespace std;

bool can(vector<vector<char>> map,int H,int W,int x,int y){
    if(H==1 && W!=1){
        if(0<x && x<W-1){
            if(map.at(x-1).at(y)=='.' && map.at(x+1).at(y)=='.'){
                return false;
            }
            else{
                return true;
            }
        }
        if(x==0){
            if(map.at(x+1).at(y)=='.'){
                return false;
            }
            else{
                return true;
            }
        }
        if(x=W-1){
            if(map.at(x-1).at(y)=='.'){
                return false;
            }
            else{
                return true;
            }
        }
    }
    if(H!=1 && W==1){
        if(0<y && y<H-1){
            if(map.at(x).at(y-1)=='.' && map.at(x).at(y+1)=='.'){
                return false;
            }
            else{
                return true;
            }
        }
        if(y==0){
            if(map.at(x).at(y+1)=='.'){
                return false;
            }
            else{
                return true;
            }
        }
        if(y=H-1){
            if(map.at(x).at(y-1)=='.'){
                return false;
            }
            else{
                return true;
            }
        }
    }
    if(H==1 &&W==1){
        return true;
    }
    if(0<x && x<W-1 && 0<y && y<H-1){
        if(map.at(x-1).at(y)=='.' && map.at(x+1).at(y)=='.' && map.at(x).at(y-1)=='.' && map.at(x).at(y+1)=='.'){
            return false;
        }
        else{
            return true;
        }
    }
    else if(x==0 && 0<y && y<H-1){
        if(map.at(x+1).at(y)=='.' && map.at(x).at(y-1)=='.' && map.at(x).at(y+1)=='.'){
            return false;
        }
        else{
            return true;
        }
    }
    else if(x==W-1 && 0<y && y<H-1){
        if(map.at(x-1).at(y)=='.' && map.at(x).at(y-1)=='.' && map.at(x).at(y+1)=='.'){
            return false;
        }
        else{
            return true;
        }
    }
    else if(0<x && x<W-1 && y==0){
        if(map.at(x-1).at(y)=='.' && map.at(x+1).at(y)=='.' && map.at(x).at(y+1)=='.'){
            return false;
        }
        else{
            return true;
        }
    }
    else if(0<x && x<W-1 && y==H-1){
        if(map.at(x-1).at(y)=='.' && map.at(x+1).at(y)=='.' && map.at(x).at(y-1)=='.'){
            return false;
        }
        else{
            return true;
        }
    }
    else if(x==0 && y==0){
        if(map.at(x+1).at(y)=='.' &&  map.at(x).at(y+1)=='.'){
            return false;
        }
        else{
            return true;
        }
    }
    else if(x==0 && y==H-1){
        if(map.at(x+1).at(y)=='.' && map.at(x).at(y-1)=='.'){
            return false;
        }
        else{
            return true;
        }
    }
    else if(x==W-1 && y==0){
        if(map.at(x-1).at(y)=='.'&& map.at(x).at(y+1)=='.'){
            return false;
        }
        else{
            return true;
        }
    }
    else if(x==W-1 && y==H-1){
        if(map.at(x-1).at(y)=='.' && map.at(x).at(y-1)=='.'){
            return false;
        }
        else{
            return true;
        }
    }
    else{
        return true;
    }
}

int main(){
    int H,W;
    cin>>H>>W;
    vector<vector<char>> map(H,vector<char>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>map.at(i).at(j);
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(map.at(i).at(j)=='#' && !can(map,H,W,i,j)){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
}