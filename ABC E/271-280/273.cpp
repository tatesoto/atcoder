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

template <class T> class persistent_stack {
    public:
    using value_type = T;
    using const_reference = const value_type &;

    private:
    class node_type;
    using node_ptr = ::std::shared_ptr<const node_type>;

    template <class... Args> static node_ptr make_node(Args &&... args) {
        return ::std::make_shared<const node_type>(::std::forward<Args>(args)...);
    }

    class node_type {
    public:
        node_ptr next;
        value_type value;

        template <class... Args>
        explicit node_type(const node_ptr &ptr, Args &&... args)
            : next(ptr), value(::std::forward<Args>(args)...) {}
    };

    node_ptr root;

    template <class... Args> persistent_stack push_p(Args &&... args) const {
        return persistent_stack(make_node(root, ::std::forward<Args>(args)...));
    }
    explicit persistent_stack(node_ptr &&r) : root(::std::move(r)) {}
    explicit persistent_stack(const node_ptr &r) : root(r) {}

    public:
    constexpr persistent_stack() noexcept : root() {}

    bool empty() const noexcept { return !static_cast<bool>(root); }

    const_reference top() const noexcept {
        assert(("called persistent_stack::top on an empty stack", !empty()));
        return root->value;
    }

    persistent_stack push(const value_type &x) const { return push_p(x); }
    persistent_stack push(value_type &&x) const { return push_p(::std::move(x)); }
    template <class... Args> persistent_stack emplace(Args &&... args) const {
        return push_p(::std::forward<Args>(args)...);
    }
    persistent_stack pop() const {
        assert(("called persistent_stack::pop on an empty stack", !empty()));
        return persistent_stack(root->next);
    }
};

/*
template<class T>
class persistent_stack;
persistent_stack は要素の last-in first-out を実現する永続的データ構造です
空間計算量 操作列に依存
テンプレートパラメータ
-class T
 要素となる型
メンバ型
-value_type
 要素の型 (T)
-const_reference
 要素への const 参照型 (const value_type &)
メンバ関数
-(destructor) ()
 時間計算量 償却 Θ(1)
-empty ()->bool
 stack が空かどうかを判定します
 時間計算量 Θ(1)
-top ()->const_reference
 先頭の要素にアクセスします
 時間計算量 Θ(1)
-push (const value_type &x)->persistent_stack
-push (value_type &&x)->persistent_stack
 x を末尾に追加した stack を作成します
 時間/空間計算量 Θ(1)
template<class ...Args>
-emplace (Args &&... args)->persistent_stack
 x を末尾に直接構築で追加した stack を作成します
 時間/空間計算量 Θ(1)
-pop ()->persistent_stack
 先頭要素を削除した stack を作成します
 時間計算量 Θ(1)
*/

/*
persistent_stack<ll> st;
ll N = 100000;
vector<ll> a;
rep(i, N){
    a.push_back(i);
}
persistent_stack<ll> pst;
map<ll,persistent_stack<ll>> mp;
mp[-1] = pst;
rep(i, N){
    mp[i] = mp[i-1].push(a.at(i));
}
rep(i, N){
    out(mp[i].top());
}
*/

int main() {
    ll Q;cin>>Q;
    persistent_stack<ll> A;
    map<ll,persistent_stack<ll>> mp;
    rep(i, Q){
        string C;cin>>C;
        if(C == "ADD"){
            ll x;cin>>x;
            A = A.push(x);
        }
        else if(C == "DELETE"){
            if(!A.empty()) A = A.pop();
        }
        else if(C == "SAVE"){
            ll y;cin>>y;
            mp[y] = A;
        }
        else{
            ll z;cin>>z;
            A = mp[z];
        }
        A.empty()? out(-1):out(A.top());
    }
}