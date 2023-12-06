#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  int r,c;
  cin >> h >> w;
  cin >> r >> c;
  int res=0;
  if(c!=1){res++;}
  if(c!=w){res++;}
  if(r!=1){res++;}
  if(r!=h){res++;}
  cout << res << '\n';
  return 0;
}
