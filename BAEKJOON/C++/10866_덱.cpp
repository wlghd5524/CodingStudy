#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int n;
    string command, data;
    cin >> n;
    getchar();
    vector<int> deque;
    for (int i = 0; i < n; i++) {
        getline(cin, command);
        if (command.find("push_front") == 0) {
            data = command.substr(11);
            deque.emplace(deque.begin(), stoi(data));
        }
        else if (command.find("push_back") == 0) {
            data = command.substr(10);
            deque.emplace_back(stoi(data));
        }
        else if (command.find("pop_front") == 0) {
            if (deque.empty() == true)
                cout << -1 << "\n";
            else {
                cout << deque.front() << "\n";
                deque.erase(deque.begin());
            }
        }
        else if (command == "pop_back") {
            if (deque.empty() == true)
                cout << -1 << "\n";
            else {
                cout << deque.back() << "\n";
                deque.pop_back();
            }
        }
        else if (command == "size")
            cout << deque.size() << "\n";
        else if (command == "empty") {
            if (deque.empty() == true)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (command == "front") {
            if (deque.empty() == true)
                cout << -1 << "\n";
            else
                cout << deque.front() << "\n";
        }
        else if (command == "back") {
            if (deque.empty() == true)
                cout << -1 << "\n";
            else
                cout << deque.back() << "\n";
        }
    }
    return 0;
}