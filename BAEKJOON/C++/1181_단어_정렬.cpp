#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(string a, string b) {
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}
int main() {
    int n, count = 0;
    cin >> n;
    vector<string> word;
    string tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        word.push_back(tmp);
    }
    sort(word.begin(), word.end(), cmp);
    for (int i = 0; i < n; i++) {
        if (word[i] == word[i + 1] && i + 1 < n)
            word.erase(word.begin() + i - 1);
    }
    for (int i = 0; i < word.size(); i++)
        cout << word[i] << "\n";
    return 0;
}