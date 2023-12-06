#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<vector<int>> data(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            char c;
            cin>>c;
            data.at(i).at(j)=c;
        }
    }
    vector<int> p={1,1,1,0,0,-1,-1,-1};
    vector<int> q={1,0,-1,1,-1,1,0,-1};
    int64_t ans=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<8;k++){
                int64_t now=0;
                int x,y;
                x=i;
                y=j;
                for(int l=0;l<N;l++){
                    now*=10;
                    now+=data.at(x).at(y);
                    x+=p.at(k);
                    y+=q.at(k);
                    x%=N;
                    x+=N;
                    y%=N;
                    y+=N;
                    x%=N;
                    y%=N;
                }
                ans=max(ans,now);
            }
        }
    }
    cout<<ans<<endl;
}