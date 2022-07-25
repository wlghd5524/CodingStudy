#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    int n, m, count = 0;
    string data;
    cin >> n >> m;
    map<string, int> cantHear;
    map<string, int> cantBoth;
    for (int i = 0; i < n; i++) {
        cin >> data;
        cantHear[data] = 0;
    }
    for (int i = 0; i < m; i++) {
        cin >> data;
        if (cantHear.find(data) != cantHear.end()) {
            cantBoth[data] = 0;
            count++;
        }
    }
    cout << count << "\n";
    for (auto iter = cantBoth.begin(); iter != cantBoth.end(); iter++)
        cout << iter->first << "\n";
}