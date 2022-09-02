#include <iostream>
using namespace std;
int main() {
    int count = 0;
    string name, word;
    getline(cin, name);
    getline(cin, word);
    while (name.find(word) != string::npos) {
        name.replace(name.find(word), word.size(), "0");
        count++;
    }
    cout << count;
}