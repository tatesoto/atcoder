#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
   double x;
   cin>>x;
   ll a=(x*1000)/100;
   ll b=a%10;
   if(b<=4){
    cout<<a/10<<endl;
   }
   else{
    cout<<a/10+1<<endl;
   }

}