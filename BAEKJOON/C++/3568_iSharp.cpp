#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;
int main() {
    int j = 0;
    string code;
    string tmp;
    string type;
    vector<string> val(1000);
    vector<string> p(1000);
    getline(cin, code);
    for (int i = 0; i < code.size(); i++) {
        if (code[i] != ' ' && code[i] != ',' && code[i] != ';') {
            tmp += code[i];
        }
        else {
            if (type.empty() == 1) {
                type = tmp;
                tmp.clear();
            }
            if (code[i] == ',' || code[i] == ';') {
                for (int x = 0; x < tmp.size(); x++) {
                    if (isalpha(tmp[x]) == 0) {
                        p[j] += tmp[x];
                    }
                    else {
                        val[j] += tmp[x];
                    }
                }
                j++;

                tmp.clear();
            }
        }
    }
    for (int i = 0; i < j; i++) {
        if (p[i].empty() == 0) {
            reverse(p[i].begin(), p[i].end());
            for (int x = 0; x < p[i].size(); x++) {
                if (p[i][x] == ']') {
                    p[i].replace(x, 1, "[");
                    continue;
                }
                if (p[i][x] == '[') {
                    p[i].replace(x, 1, "]");
                    continue;
                }
            }
        }
        cout << type << p[i] << " " << val[i] << ";\n";
    }
    return 0;
}