#include <iostream>
#include <string>
미완
using namespace std;

int main() {
    string inp;
    bool isPan = true;
    for(;;) {
        getline(cin,inp);
        for(int i = 0; i <= inp.size(); i++) {
            for(int j = 56; j <= 69; j++) {
                if(inp.find(j) == string::npos) {
                isPan = false;
                }
            }
            
        }
        if(isPan == true) {
        cout << "Y";
        }
        else {
            cout << "N";
        }
    }
    
    
    return 0;
}