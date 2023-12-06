#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define out(x) cout<<x<<endl
#define all(v) v.begin(),v.end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;

struct Edge
{
    ll to,cap,rev;
};

//計算量は、O(FM)
//0-indexed
class MaximumFlow{
public:
    vector<bool> used;
    vector<vector<Edge>> G;

    //頂点数Nの残余グラフ
    void init(ll N){
        used.resize(N+1,false);
        G.resize(N+1);
    }
    
    //頂点aから頂点bに向かう、上限cリットル/秒の辺を追加
    void add_edge(ll a,ll b,ll c){
        G.at(a).push_back(Edge{b,c,(ll)(G.at(b).size())});
        G.at(b).push_back(Edge{a,0,(ll)(G.at(a).size()-1)});
    }

    //深さ優先探索(Fはスタートからposに到達する過程での、残余グラフの辺の容量の最小値)
    //返り値は流したフローの量(流せない場合は0を返す)
    ll dfs(ll pos,ll goal,ll F){
        //goalにつけば、フローを流せる
        if(pos==goal) return F;
        used.at(pos)=true;
        //探索
        for(auto &x:G.at(pos)){
            //容量0の辺は使えない
            if(x.cap==0) continue;

            //すでに行った頂点に行かない
            if(used.at(x.to)) continue;

            //目的地までのパスを探す
            ll flow=dfs(x.to,goal,min(F,x.cap));

            if(flow>=1){
                x.cap-=flow;
                G.at(x.to).at(x.rev).cap+=flow;
                return flow;
            }
        }
        return 0;
    }

    ll max_flow(ll s,ll t){
        ll Total_Flow=0;
        while(true){
            rep(i,used.size()){
                used.at(i)=false;
            }
            ll F=dfs(s,t,INF);
            if(F==0) break;
            Total_Flow+=F;
        }
        return Total_Flow;
    }
};

int main() {
    
}