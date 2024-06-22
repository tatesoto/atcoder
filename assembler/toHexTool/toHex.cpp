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

ll to_decimal(string n) {
    ll num = 0;
    for(auto c : n) {
        if('0' <= c && c <= '9') {
            num = num * 10 + (c - '0');
        }
        else if('A' <= c && c <= 'F') {
            num = num * 10 + (c - 'A' + 10);
        }
        else if('a' <= c && c <= 'f') {
            num = num * 10 + (c - 'a' + 10);
        }
    }
    return num;
}

string to_hex (string n) {
    ll num = to_decimal(n);
    string res;
    if(num < 0) {
        num = -num;
        res += '-';
    }
    string hex = "0123456789abcdef";
    string tmp;
    while(num > 0) {
        tmp += hex[num % 16];
        num /= 16;
    }
    if(tmp.empty()) tmp = "0";
    reverse(tmp.begin(), tmp.end());
    res += tmp;
    return res;
}

vector<string> read_file(string filename) {
    ifstream ifs(filename);
    if(!ifs) {
        cerr << "File not found." << endl;
        exit(1);
    }
    vector<string> codes;
    string line;
    while(getline(ifs, line)) {
        if(line == "ADDRESS_RADIX = DEC;") {
            codes.push_back("ADDRESS_RADIX = HEX;");
            continue;
        }
        if(line.find(":") == string::npos) {
            codes.push_back(line);
            continue;
        }
        string code = line.substr(line.find(":"));
        stringstream ss(line);
        string num;
        ss >> num;
        string res;
        res = to_hex(num) + " " + code;
        codes.push_back(res);
    }
    return codes;
}

void write_file(string filename, vector<string> codes) {
    ifstream infile(filename);
    if(infile.good()) {
        string warning = "File " + filename + " already exists. Do you want to overwrite it? (y/n)";
        out(warning);
        char c;
        cin >> c;
        if(c != 'y' && c != 'Y') {
            out("File not overwritten.");
            return;
        }
    }

    ofstream ofs(filename);
    for(auto code : codes) {
        ofs << code << '\n';
    }
}

// input: mnemonicコードの書かれたテキストファイル(*.txt).
// output: バイナリコードの書かれたテキストファイル(*_binary.txt).
// mnemonicコードの書き方は以下の通り.
// ・命令名と引数はスペース区切り.
// ・引数の最後にカンマ(,)やセミコロン(;)があっても無視される.
// ・大文字小文字は区別しない.
// ・引数がレジスタの場合、Rをつけなくてもよい.
// ・LD, ST命令の第2引数は、d(rb)の形で書く.

int main(int argc, char* argv[]) {
    string input_filename = "beforehex.txt";
    vector<string> codes = read_file(input_filename);
    string output_filename = input_filename.substr(0, input_filename.find('.')) + "_hex.txt";
    write_file(output_filename, codes);
    out("File written.");
    return 0;
}