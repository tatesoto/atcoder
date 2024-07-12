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

vector<ll> make_array_test(ll siz, bool is_unique = false, ll left = 1, ll right = 100) {
    assert(left <= right);
    assert(!(is_unique && right - left + 1 < siz));
    mt19937_64 rnd(chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count());
    uniform_int_distribution<int> dist_N(left, right);
    vector<ll> res;
    if(is_unique) {
        set<ll> st;
        while(st.size() < siz) {
            st.insert(dist_N(rnd));
        }
        res = vector<ll>(all(st));
        shuffle(all(res), rnd);
    } else {
        res = vector<ll>(siz);
        rep(i, siz) res[i] = dist_N(rnd);
    }
    return res;
}

vector<vector<ll>> make_test_case(ll q, ll minsiz = 1, ll maxsiz = 100, bool is_unique = false, ll left = 1, ll right = 100) {
    vector<vector<ll>> res;
    mt19937_64 rnd(chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count());
    uniform_int_distribution<int> dist_N(minsiz, maxsiz);
    rep(i, q) {
        ll siz = dist_N(rnd);
        res.push_back({siz});
        res.push_back(make_array_test(siz, is_unique, left, right));
    }
    res.push_back({0});
    return res;
}

void write_file(string filename, vector<vector<ll>> test) {
    ifstream infile(filename);
    if(infile.good()) {
        string warning = "File " + filename + " already exists. Do you want to overwrite it? (Y/n)";
        out(warning);
        char c;
        cin >> c;
        if(c != 'y' && c != 'Y') {
            out("File not overwritten.");
            return;
        }
    }

    ofstream ofs(filename);
    for(auto vec : test) {
        ll siz = vec.size();
        rep(i, siz) {
            ofs << vec[i];
            if(i != siz - 1) ofs << ' ';
        }
        ofs << '\n';
    }
    ofs.close();
    out("File written successfully.");
    return;
}

int main(int argc, char* argv[]) {
    //Configurations
    ll q = 10;  // number of testcases
    ll minsiz = 1; // minsize of array
    ll maxsiz = 100;    // maxsize of array
    bool is_unique = false; // whether the array is unique or not
    ll left = 10;    // minimum value of array
    ll right = 1000; // maximum value of array
    string foldername = "ArrayTest"; // folder to write the test
    string filename = "small"; // filename to write the test

    auto test = make_test_case(q, minsiz, maxsiz, is_unique, left, right);
    write_file(foldername + "/" + filename, test);
    return 0;
}