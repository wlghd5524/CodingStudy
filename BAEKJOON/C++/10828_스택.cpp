#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main() {
    int n;
    string command, data;
    cin >> n;
    getchar();
    vector<int> stack;
    for (int i = 0; i < n; i++) {
        getline(cin, command);
        if (command.find("push") == 0) {
            data = command.substr(5);
            stack.emplace_back(stoi(data));
        }
        else if (command == "pop") {
            if (stack.empty() == true)
                cout << -1 << "\n";
            else {
                cout << stack.back() << "\n";
                stack.pop_back();
            }
        }
        else if (command == "size")
            cout << stack.size() << "\n";
        else if (command == "empty") {
            if (stack.empty() == true)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (command == "top") {
            if (stack.empty() == true)
                cout << -1 << "\n";
            else 
                cout << stack.back() << "\n";
        }
    }
    return 0;
}