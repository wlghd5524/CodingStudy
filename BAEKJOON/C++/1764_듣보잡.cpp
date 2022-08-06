#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    int n, m, count = 0;
    string data;
    cin >> n >> m;
    map<string, int> cant_hear;
    map<string, int> cant_both;
    for (int i = 0; i < n; i++) {
        cin >> data;
        cant_hear[data] = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> data;
        if (cant_hear.find(data) != cant_hear.end()) {
            cant_both[data] = 0;
            count++;
        }
    }
    cout << count << "\n";
    for (auto iter = cant_both.begin(); iter != cant_both.end(); iter++)
        cout << iter->first << "\n";
    return 0;
}