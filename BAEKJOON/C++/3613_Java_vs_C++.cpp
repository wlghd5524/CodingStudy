#include <iostream>
#include <string>
using namespace std;
int main() {
    string name;
    cin >> name;
    if (name.find('_') == string::npos && name[0] > 91) {
        for (int i = 0; i < name.size(); i++) {
            if (name[i] < 91) {
                name[i] += 32;
                name.insert(i, 1, '_');
            }
        }
    }
    else if (name.find('_') != string::npos && name[0] != '_' && name.back() != '_') {
        for (int i = 0; i < name.size(); i++) {
            if (name[i] < 91) {
                cout << "Error!";
                return 0;
            }
            if (name[i] == '_') {
                if (name[i + 1] == '_' || name[i + 1] < 91) {
                    cout << "Error!";
                    return 0;
                }
                name[i + 1] -= 32;
                name.erase(i, 1);
            }
        }
    }
    else {
        cout << "Error!";
        return 0;
    }
    cout << name;
    return 0;
}