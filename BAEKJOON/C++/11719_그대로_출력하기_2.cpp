#include <iostream>
using namespace std;
int main() {
    string s;
    while(1) {
        if(cin.eof()) {
            break;
        }
        getline(cin,s);
        cout << s << "\n";
    }
    return 0;
}