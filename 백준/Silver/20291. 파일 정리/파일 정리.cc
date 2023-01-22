#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    int j = 0;
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string fileName;
    string extension;
    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        cin >> fileName;
        for (j = fileName.size() - 1; fileName[j] != '.'; j--){}
        for (j += 1; j < fileName.size(); j++)
            extension += fileName[j];
        m[extension]++;
        extension.clear();
    }
    for (auto iter = m.begin(); iter != m.end(); iter++)
        cout << iter->first << " " << iter->second << "\n";
    return 0;
}