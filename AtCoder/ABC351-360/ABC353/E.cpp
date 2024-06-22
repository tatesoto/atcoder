#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define out(x) cout<<x<<'\n'
#define all(v) v.begin(),v.end()
#define rep(i,n) for(int i=0;i<(ll)(n);i++)
template<class T> inline bool chmin(T& a, T b) {if(a > b){a = b; return true;} else {return false;}};
template<class T> inline bool chmax(T& a, T b) {if(a < b){a = b; return true;} else {return false;}};
const ll INF=(1LL<<60);
const ll mod=998244353;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};
/* Trie 木： 文字の種類(char_size)、int型で0に対応する文字(base)
    Trie<26, 'a'> 変数名; で宣言する（英小文字の場合)  
    insert(word): 単語 word を Trie 木に挿入する
    search(word): 単語 word が Trie 木にあるか判定する
    start_with(prefix):  prefix が一致する単語が Trie 木にあるか判定する
    count_start_with(prefix):  prefix が一致する単語が Trie 木にいくつあるかを返す
    計算量：insert, search ともに O(M)（Mは単語の長さの合計）
*/
template <ll char_size, ll base>    //文字の種類と、0番目にあたるもの (ex) <26,'a'>なら英小文字
struct Trie {
    //頂点
    struct Node {
        vector<ll> next;    //子の頂点番号（存在しなければ-1)を格納
        vector<ll> accept;  //末端がこの頂点になる文字列の str_id を保存
        ll c;              //base からの間隔をint型で表現したもの
        ll common;         //いくつの文字列がこの頂点を共有しているか
        Node(ll c_) : c(c_), common(0) {
            next.assign(char_size, -1);
        }
    };

    vector<Node> nodes;     //trie木本体
    ll root;
    Trie(): root(0) {
        //初期化。最初は根のみ
        nodes.push_back(Node(root));
    }

    //単語の挿入
    void insert(const string &word, ll word_id) {
        ll node_id = 0;
        rep(i, word.size()){
            ll c = int(word[i] - base);
            ll &next_id = nodes[node_id].next[c];
            if(next_id == -1){      //次の頂点が存在しなければ追加
                next_id = nodes.size();
                nodes.push_back(Node(c));
            }
            ++nodes[node_id].common;
            node_id = next_id;
        }
        ++nodes[node_id].common;
        nodes[node_id].accept.push_back(word_id);   //単語の終端なので、頂点に単語番号を入れておく
    }
    //単語の挿入
    void insert(const string &word) {
        insert(word, nodes[0].common);
    }

    //単語の検索
    bool search(const string &word, bool prefix = false) {
        ll node_id = 0;
        rep(i, word.size()){
            ll c = int(word[i] - base);
            ll next_id = nodes[node_id].next[c];
            if (next_id == -1){
                return false;
            }
            node_id = next_id;
        }
        if (prefix){
            return true;
        }
        else {
            return nodes[node_id].accept.size() > 0;    //最後の頂点が単語の終点となることがあるか
        }
    }

    //prefix(接頭辞)で始まる単語が存在するか
    bool start_with(const string &prefix){
        return search(prefix, true);
    }

    //prefix(接頭辞)で始まる単語の数
    ll count_start_with(const string &prefix){
        ll node_id = 0;
        rep(i, prefix.size()){
            ll c = int(prefix[i] - base);
            ll next_id = nodes[node_id].next[c];
            if (next_id == -1) return 0;
            node_id = next_id;
        }
        return nodes[node_id].common;
    }

};

int main() {
    ll N;cin>>N;
    vector<string> S(N);
    Trie<26, 'a'> trie;
    rep(i,N) {
        string s;cin>>s;
        S[i] = s;
        trie.insert(s);
    }
    ll ans = 0;
    auto dfs = [&](auto dfs, ll node, string s, ll depth) -> void {
        //現在の頂点で終わる単語の数を数える.ただし自分自身を除く．
        if(trie.nodes[node].accept.size() > 0) {
            if(depth == s.size()) {
                ans += (trie.nodes[node].accept.size() -1)*(depth);
            }
            else {
                ans += trie.nodes[node].accept.size()*(depth);
            }
        }

        rep(i, 26) {
            if(depth < s.size() && s[depth] == 'a'+i) {
                if(trie.nodes[node].next[i] != -1) {
                    ll next_node = trie.nodes[node].next[i];
                    dfs(dfs, next_node, s, depth+1);
                }
            }
            else {
                if(trie.nodes[node].next[i] != -1) {
                    ll next_node = trie.nodes[node].next[i];
                    ans += trie.nodes[next_node].common*(depth);
                }
            }
        }
    };
    rep(i,N) {
        string s = S[i];
        dfs(dfs, 0, s, 0);
    }
    out(ans/2);
    
}