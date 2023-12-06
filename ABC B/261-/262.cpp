#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> data(n, vector<bool>(n,false)); //1と2を結ぶ線分がある→(1,2)がtrue
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u-=1;
        v-=1;
        data.at(u).at(v)=data.at(v).at(u)=true;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(data.at(i).at(j) && data.at(j).at(k) && data.at(k).at(i)){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}