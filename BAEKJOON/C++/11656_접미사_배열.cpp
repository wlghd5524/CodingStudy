#include <iostream>
#include <map>
using namespace std;
int main() {
    string word;
    string tmp;
    cin >> word;
    map<string, int> m;
    for (int i = 0; i < word.size(); i++) {
        for (int j = i; j < word.size(); j++)
            tmp += word[j];
        m[tmp] = 0;
        tmp.clear();
    }
    for (auto iter = m.begin(); iter != m.end(); iter++)
        cout << iter->first << "\n";
}