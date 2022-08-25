#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    string word;
    cin >> n >> m;
    set<string> s;
    for (int i = 0; i < n; i++) {
        cin >> word;
        s.insert(word);
    }
    cin.ignore();
    for (int i = 0; i < m; i++) {
        getline(cin, word);
        string tmp;
        for (int j = 0; j < word.size(); j++) {
            if (word[j] != ',') {
                tmp += word[j];
            }
            else {
                s.erase(tmp);
                tmp.clear();
            }
            if (j + 1 == word.size()) {
                s.erase(tmp);
                tmp.clear();
            }
        }
        cout << s.size() << "\n";
    }
}