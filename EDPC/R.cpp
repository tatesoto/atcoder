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
const ll mod=1e9+7;
using Graph = vector<vector<ll>>;
using Network = vector<vector<pair<ll,ll>>>;
using Grid = vector<string>;
const vector<ll> dx = {0, 1, 0, -1};
const vector<ll> dy = {1, 0, -1, 0};

template<typename T>
struct mat {
    // 行列m
    vector<vector<T>> m;
    // コンストラクタ:第1引数⇒行数、第2引数⇒列数、第3引数⇒初期値
    mat():m(vector<vector<T>>()){}
    mat(int h,int w):m(vector<vector<T>>(h,vector<T>(w))){}
    mat(int h,int w, T d):m(vector<vector<T>>(h,vector<T>(w,d))){}
    // 添字演算子
    vector<T> operator[](const int i) const {return m[i];} //読み取り
    vector<T>& operator[](const int i){return m[i];} //書き込み
    vector<T> at(const int i) const {return m.at(i);} //読み取り
    vector<T>& at(const int i){return m.at(i);} //書き込み
    // 行数・列数
    int nrow = m.size();
    int ncol = m[0].size();
    // 行列同士の演算
    mat& operator=(const mat& a){return *a;}
    mat& operator+=(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] += a[i][j]; return *this;}
    mat& operator-=(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);rep(i,nrow)rep(j,ncol)m[i][j] -= a[i][j]; return *this;} 
    mat& operator*=(const mat& a){assert(ncol == a.nrow);mat<T> m2(nrow, a.ncol, 0);rep(i,nrow)rep(j,a.ncol)rep(k,ncol){m2[i][j] += m[i][k]*a[k][j];m2[i][j] %= mod;}ncol = a.ncol;rep(i,nrow)m[i].resize(ncol);rep(i,nrow)rep(j,ncol)m[i][j] = m2[i][j]%mod; return *this;}
    mat operator+(const mat& a) const { return mat(*this) += a;}
    mat operator-(const mat& a) const { return mat(*this) -= a;}
    mat operator*(const mat& a) const { return mat(*this) *= a;}
    bool operator==(const mat& a){assert(ncol == a.ncol && nrow == a.nrow);bool flg = true;rep(i,nrow)rep(j,ncol)if(m[i][j] != a[i][j])flg = false; return flg;}
    // 行列とスカラの演算
    mat& operator+=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] += a;return *this;}
    mat& operator-=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] -= a;return *this;}
    mat& operator*=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] *= a;return *this;}
    mat& operator/=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] /= a;return *this;}
    mat& operator%=(const T& a){rep(i,nrow)rep(j,ncol)m[i][j] %= a;return *this;}
    mat operator+(const T& a) const { return mat(*this) += a;}
    mat operator-(const T& a) const { return mat(*this) -= a;}
    mat operator*(const T& a) const { return mat(*this) *= a;}
    mat operator/(const T& a) const { return mat(*this) /= a;}
    mat operator%(const T& a) const { return mat(*this) %= a;}
    // 回転（degの数だけ時計回りに90度回転）
    mat& rot(int deg){
        mat<T> m2(ncol, nrow);
        if(deg == 1 || deg == 3){
            if(deg == 1)rep(i,nrow)rep(j,ncol)m2[j][nrow -i -1] = m[i][j];
            if(deg == 3)rep(i,nrow)rep(j,ncol)m2[ncol -j -1][i] = m[i][j];
            swap(ncol,nrow); // 列数と行数を入れ替える
            m.resize(nrow);rep(i,nrow)m[i].resize(ncol); //リサイズ
        }
        if(deg == 2)rep(i,nrow)rep(j,ncol)m2[nrow -i -1][ncol -j -1] = m[i][j];
        rep(i,nrow)rep(j,ncol)m[i][j] = m2[i][j];
        return *this;
    }
    // 標準出力
    void show(){
        rep(i,nrow)rep(j,ncol){
            if(j != 0)cout << " ";
            cout << m[i][j];
            if(j==ncol-1)cout << endl;
        }
        return ;
    }
};

//行列累乗
mat<ll> mat_pow(mat<ll> A, ll n) {
    ll siz = A.nrow;
    mat<ll> res(siz, siz, 0);
    rep(i, siz) res[i][i] = 1;
    if(n == 0) return res;
    auto tmp = mat_pow(A, n/2);
    res *= tmp;
    res %= mod;
    res *= tmp;
    res %= mod;
    if(n%2==1) res *= A;
    res %= mod;
    return res;
}

int main() {
    ll N, K;cin>>N>>K;
    mat<ll> A(N, N, 0);
    rep(i, N) {
        rep(j, N) {
            cin>>A[i][j];
        }
    }
    mat<ll> An = mat_pow(A, K);
    ll ans = 0;
    rep(i, N) {
        rep(j, N) {
            ans += An[i][j];
            ans %= mod;
        }
    }
    out(ans%mod);
}