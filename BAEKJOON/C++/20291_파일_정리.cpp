#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    int j = 0;
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string file_name;
    string extension;
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        cin >> file_name;
        for (j = file_name.size() - 1; file_name[j] != '.'; j--){}
        for (j += 1; j < file_name.size(); j++)
            extension += file_name[j];
        m[extension]++;
        extension.clear();
    }
    for (auto iter = m.begin(); iter != m.end(); iter++)
        cout << iter->first << " " << iter->second << "\n";
    return 0;
}