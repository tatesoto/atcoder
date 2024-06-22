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

struct Instruction {
    string op;
    string rs;
    string rd;
    string op3;
    string d;
};

struct Mnemonic {
    string name;
    vector<string> args;
    string comment;
};

const set<string> instr_rs_rd = {"ADD", "SUB", "AND", "OR", "XOR", "CMP", "MOV"};
const set<string> instr_rd_d = {"SLL", "SLR", "SRL", "SRA"};
const set<string> instr_rd = {"IN"};
const set<string> instr_rs = {"OUT"};
const set<string> instr_ra_rb_d = {"LD", "ST"};
const set<string> instr_rb_d = {"LI", "ADDI", "SUBI", "CMPI"};
const set<string> instr_d = {"B", "BE", "BLT", "BLE", "BNE"};
const set<string> instr_no_arg = {"NOP", "HLT"};
bool comment = false;


const map<string, Instruction> instr = {
    {"ADD", {"11", "rs", "rd", "0000", "0000"}},
    {"SUB", {"11", "rs", "rd", "0001", "0000"}},
    {"AND", {"11", "rs", "rd", "0010", "0000"}},
    {"OR", {"11", "rs", "rd", "0011", "0000"}},
    {"XOR", {"11", "rs", "rd", "0100", "0000"}},
    {"CMP", {"11", "rs", "rd", "0101", "0000"}},
    {"MOV", {"11", "rs", "rd", "0110", "0000"}},
    {"SLL", {"11", "000", "rd", "1000", "d"}},
    {"SLR", {"11", "000", "rd", "1001", "d"}},
    {"SRL", {"11", "000", "rd", "1010", "d"}},
    {"SRA", {"11", "000", "rd", "1011", "d"}},
    {"IN", {"11", "000", "rd", "1100", "0000"}},
    {"OUT", {"11", "rs", "000", "1101", "0000"}},
    {"HLT", {"11", "000", "000", "1111", "0000"}},
    {"LD", {"00", "ra", "rb", "", "d"}},
    {"ST", {"01", "ra", "rb", "", "d"}},
    {"LI", {"10", "000", "rb", "", "d"}},
    {"ADDI", {"10", "001", "rd", "", "d"}},
    {"SUBI", {"10", "010", "rd", "", "d"}},
    {"CMPI", {"10", "011", "rd", "", "d"}},
    {"B", {"10", "100", "000", "", "d"}},
    {"BE", {"10", "111", "000", "", "d"}},
    {"BLT", {"10", "111", "001", "", "d"}},
    {"BLE", {"10", "111", "010", "", "d"}},
    {"BNE", {"10", "111", "011", "", "d"}},
    {"NOP", {"11", "111", "111", "1111", "1111"}}
};

string to_binary(string n, int digit) {
    int num = stoi(n);
    string res;
    if(num < 0) {
        num = -num;
        for(int i = 0; i < digit; i++) {
            res += to_string(num % 2);
            num /= 2;
        }
        for(int i = 0; i < digit; i++) {
            if(res[i] == '0') res[i] = '1';
            else res[i] = '0';
        }
        bool carry = true;
        for(int i = 0; i < digit; i++) {
            if(carry) {
                if(res[i] == '0') {
                    res[i] = '1';
                    carry = false;
                }
                else {
                    res[i] = '0';
                    carry = true;
                }
            }
        }
    }
    else {
        for(int i = 0; i < digit; i++) {
            res += to_string(num % 2);
            num /= 2;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

ll to_decimal(string n) {
    ll res = 0;
    int digit = n.size();
    if(n[0] == '0') {
        for(int i = 0; i < digit; i++) {
            res += (n[i] - '0') * pow(2, digit - i - 1);
        }
    }
    else {
        for(int i = 0; i < digit; i++) {
            if(n[i] == '0') n[i] = '1';
            else n[i] = '0';
        }
        bool carry = true;
        for(int i = digit - 1; i >= 0; i--) {
            if(carry) {
                if(n[i] == '0') {
                    n[i] = '1';
                    carry = false;
                }
                else {
                    n[i] = '0';
                    carry = true;
                }
            }
        }
        
        for(int i = 1; i < digit; i++) {
            res += (n[i] - '0') * pow(2, digit - i - 1);
        }
        res = -res;
    }
    return res;
}

string to_16bit(Mnemonic code) {
    string instr_name = code.name;
    if(instr_rs_rd.count(instr_name)) {
        string rs = code.args[1];
        string rd = code.args[0];
        rs = to_binary(rs, 3);
        rd = to_binary(rd, 3);
        return instr.at(instr_name).op + rs + rd + instr.at(instr_name).op3 + instr.at(instr_name).d;
    }
    else if(instr_rd_d.count(instr_name)) {
        string rd = code.args[0];
        string d = code.args[1];
        rd = to_binary(rd, 3);
        d = to_binary(d, 4);
        return instr.at(instr_name).op + instr.at(instr_name).rs + rd + instr.at(instr_name).op3 + d;
    }
    else if(instr_rd.count(instr_name)) {
        string rd = code.args[0];
        rd = to_binary(rd, 3);
        return instr.at(instr_name).op + instr.at(instr_name).rs + rd + instr.at(instr_name).op3 + instr.at(instr_name).d;
    }
    else if(instr_rs.count(instr_name)) {
        string rs = code.args[0];
        rs = to_binary(rs, 3);
        return instr.at(instr_name).op + rs + instr.at(instr_name).rd + instr.at(instr_name).op3 + instr.at(instr_name).d;
    }
    else if(instr_ra_rb_d.count(instr_name)) {
        string ra = code.args[0];
        string rb = code.args[1];
        string d = code.args[2];
        ra = to_binary(ra, 3);
        rb = to_binary(rb, 3);
        d = to_binary(d, 8);
        return instr.at(instr_name).op + ra + rb + instr.at(instr_name).op3 + d;
    }
    else if(instr_rb_d.count(instr_name)) {
        string rb = code.args[0];
        string d = code.args[1];
        rb = to_binary(rb, 3);
        d = to_binary(d, 8);
        return instr.at(instr_name).op + instr.at(instr_name).rs + rb + instr.at(instr_name).op3 + d;
    }
    else if(instr_d.count(instr_name)) {
        string d = code.args[0];
        d = to_binary(d, 8);
        return instr.at(instr_name).op + instr.at(instr_name).rs + instr.at(instr_name).rd + instr.at(instr_name).op3 + d;
    }
    else if(instr_no_arg.count(instr_name)) {
        return instr.at(instr_name).op + instr.at(instr_name).rs + instr.at(instr_name).rd + instr.at(instr_name).op3 + instr.at(instr_name).d;
    }
    else {
        return "Invalid instruction";
    }
}

Mnemonic arrange_code(Mnemonic code) {
    Mnemonic res;
    res.name = code.name;
    transform(res.name.begin(), res.name.end(), res.name.begin(), ::toupper);
    for(auto arg : code.args) {
        string new_arg = arg;
        transform(new_arg.begin(), new_arg.end(), new_arg.begin(), ::toupper);
        if(new_arg.back() == ',' || new_arg.back() == ';') new_arg.pop_back();
        if(new_arg.find('(') != string::npos) {
            string rb = new_arg.substr(new_arg.find('(') + 1, new_arg.find(')') - new_arg.find('(') - 1);
            if(rb.front() == 'R') rb = rb.substr(1, rb.size() - 1);
            string d = new_arg.substr(0, new_arg.find('('));
            res.args.push_back(rb);
            res.args.push_back(d);
        }
        else {
            if(new_arg.front() == 'R') new_arg = new_arg.substr(1, new_arg.size() - 1);
            res.args.push_back(new_arg);
        }
    }
    return res;
}

vector<string> assembler(vector<Mnemonic> codes, bool to_verilog = false, bool to_mif = false) {
    vector<string> res;
    int i = 0;
    for(auto code : codes) {
        if(code.name == "comment") {
            res.push_back(code.comment);
            continue;
        }
        // NOP命令が最初にない場合は追加する.
        if(i == 0 && code.name != "NOP") {
            Mnemonic new_code;
            new_code.name = "NOP";
            string binary_code = to_16bit(new_code);
            ll num = to_decimal(binary_code);
            if(to_verilog) {
                binary_code = "memory[" + to_string(i) + "] = 16'b" + binary_code + "; // " + new_code.name;
            }
            if(to_mif) {
                binary_code = to_string(i) + " : " + to_string(num) + ";";
            }
            res.push_back(binary_code);
            i++;
        }
        Mnemonic new_code = arrange_code(code);
        string binary_code = to_16bit(new_code);
        if(to_verilog) {
            binary_code = "memory[" + to_string(i) + "] = 16'b" + binary_code + "; // " + code.name;
            for(auto arg : code.args) {
                binary_code += " " + arg;
            }
        }
        if(to_mif) {
            ll num = to_decimal(binary_code);
            binary_code = to_string(i) + " : " + to_string(num) + ";";
        }
        res.push_back(binary_code);
        cout << '+';
        if(i % 10 == 0) cout << i << '\n';
        i++;
    }
    cout << '\n';
    return res;
}

vector<Mnemonic> read_file(string filename) {
    ifstream ifs(filename);
    if(!ifs) {
        cerr << "File not found." << endl;
        exit(1);
    }
    vector<Mnemonic> codes;
    string line;
    while(getline(ifs, line)) {
        Mnemonic code;
        if(line == "") {
            code.comment = "";
            code.name = "comment";
            codes.push_back(code);
            continue;
        }
        if(line.find("//") != string::npos) {
            code.comment = line;
            code.name = "comment";
            codes.push_back(code);
            continue;
        }
        if(line.find("/*") != string::npos) {
            code.comment = line;
            code.name = "comment";
            codes.push_back(code);
            comment = true;
            continue;
        }
        if(comment) {
            code.comment = line;
            code.name = "comment";
            codes.push_back(code);
            if(line.find("*/") != string::npos) comment = false;
            continue;
        }
        stringstream ss(line);
        ss >> code.name;
        string arg;
        while(ss >> arg) {
            code.args.push_back(arg);
        }
        codes.push_back(code);
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
    string input_filename = "sort/combSort.txt";
    vector<Mnemonic> codes = read_file(input_filename);
    vector<string> binary_codes = assembler(codes, false, true);
    string output_filename = input_filename.substr(0, input_filename.find('.')) + "_binary.txt";
    write_file(output_filename, binary_codes);
    return 0;
}