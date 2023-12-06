//無理でした。。。


#include <bits/stdc++.h>
using namespace std;

void print_int(int x){
    cout<<x<<endl;
}
void print_vec(vector<int> vec){
    cout<< "[ ";
    for(int i=0;i<vec.size();i++){
        cout<<vec.at(i)<<" ";
    }
    cout<<"]"<<endl;
}
string read_name(){
    string name,equal;
    cin>>name>>equal;
    return name;
}

int read_int(map<string,int> &var_int){
    string val;
    cin>>val;
    if(isdigit(val.at(0))){
        return stoi(val);
    }
    else{
        return var_int.at(val);
    }
}
int calc_int(map<string,int> &var_int){
    string symbol="";
    int result=0;
    while(symbol != ";"){
        int val =read_int(var_int);

        if(symbol==""){
            result=val;
        }
        if(symbol=="+"){
            result+=val;
        }
        if(symbol=="-"){
            result-=val;
        }

        cin>>symbol;
    }
    return result;
}

vector<int> read_vec_val(map<string,int> &var_int){
    vector<int> result;
    string symbol="";
    while(symbol!="]"){
        int val =read_int(var_int);
        result.push_back(val);
        cin>>symbol;
    }
    return result;
}

vector<int> read_vec(map<string,int> &var_int,map<string,vector<int>> &var_vec){
    string val;
    cin>>val;
    if(val=="["){
        return read_vec_val(var_int);
    }
    else{
        return var_vec.at(val);
    }
}

vector<int> calc_vec(map<string,int> &var_int,map<string,vector<int>> $var_vec){
    string symbol;
    vector<int> result;
    while(symbol != ";"){
        

        
    }
}


int main(){
    int N;
    cin>>N;

    map<string,int> var_int;
    map<string,vector<int>> var_vec;

    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        if(s=="int"){
            string name=read_name();
            var_int[name]=calc_int(var_int);
        }
        if(s=="print_int"){
            int x;
            cin>>x;
            print_int(x);
        }
        if(s=="print_vec"){
            vector<int> vec;
            
        }
    }

}