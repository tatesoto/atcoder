#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp[10][10];
void solve(int n,int m){
  if(dp[n][m].size()) return;
  if(n==1){
    for(int i=1;i<=m;i++){
      dp[n][m].push_back({i});
    }
  }
  else{
    for(int k=1;k<=m;k++){
      if(n-1<=k-1){
        solve(n-1,k-1);
        for(int i=0;i<dp[n-1][k-1].size();i++){
          vector<int> a=dp[n-1][k-1][i];
          a.push_back(k);
          dp[n][m].push_back(a);
        }
      }
    }
  }
}

int main() {
  int n,m;
  cin>>n>>m;
  solve(n,m);
  sort(dp[n][m].begin(),dp[n][m].end());
  for(int i=0;i<dp[n][m].size();i++){
    for(int j=0;j<n;j++)
    cout<<dp[n][m][i][j]<<" ";
    cout<<endl;
  }
}
