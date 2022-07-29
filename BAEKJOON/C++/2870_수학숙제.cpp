#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(string a, string b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] < b[i])
                return a < b;
        }
    }
    return a.size() < b.size();
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string str[n];
    string tmp;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        for (int j = 0; j < str[i].size(); j++) {
            if (isdigit(str[i][j]) != 0)
                tmp = tmp + str[i][j];
            if (isdigit(str[i][j]) == 0 || j == str[i].size() - 1) {
                if (tmp.size() != 0) {
                    while (tmp[0] == '0')
                        tmp.erase(0, 1);
                    if (tmp.size() == 0)
                        v.emplace_back("0");
                    else
                        v.emplace_back(tmp);
                    tmp.clear();
                }
            }
        }
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
    return 0;
}