#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    int n;
    string command, data;
    cin >> n;
    getchar();
    vector<int> queue;
    for (int i = 0; i < n; i++) {
        getline(cin, command);
        if (command.find("push") == 0) {
            data = command.substr(5);
            queue.emplace_back(stoi(data));
        }
        else if (command == "pop") {
            if (queue.empty() == true)
                cout << -1 << "\n";
            else {
                cout << queue.back() << "\n";
                queue.pop_back();
            }
        }
        else if (command == "size")
            cout << queue.size() << "\n";
        else if (command == "empty") {
            if (queue.empty() == true)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (command == "top") {
            if (queue.empty() == true)
                cout << -1 << "\n";
            else 
                cout << queue.back() << "\n";
        }
    }
}