#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    string name, command;
    unordered_map<string, int> um;
    unordered_map<int, string> um2;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> name;
        um[name] = i;
        um2[i] = name;
    }
    for (int i = 0; i < m; i++) {
        cin >> command;
        if (um.find(command) != um.end())
            cout << um.find(command)->second << "\n";
        else
            cout << um2.find(stoi(command))->second << "\n";
    }
}