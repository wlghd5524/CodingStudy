#include <iostream>
#include <vector>
using namespace std;
int main() {
    int max_size = 0;
    vector<string> v;
    for (int i = 0; i < 5; i++) {
        string tmp;
        getline(cin, tmp);
        if (max_size < tmp.size()) {
            max_size = tmp.size();
        }
        v.emplace_back(tmp);
    }
    for (int i = 0; i < max_size; i++) {
        for (int j = 0; j < 5; j++) {
            if (v[j].size() <= i) {
                continue;
            }
            if (v[j][i] != ' ') {
                cout << v[j][i];
            }
        }
    }
}