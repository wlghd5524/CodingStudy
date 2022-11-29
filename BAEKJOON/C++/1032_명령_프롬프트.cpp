#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<string> files(n);
    string result;
    for(int i = 0;i<n;i++) {
        cin >> files[i];
    }
    for(int i = 0;i<files[0].size();i++) {
        char tmp = files[0][i];
        bool is_correct = true;
        for(int j = 1;j<n;j++) {
            if(tmp!=files[j][i]) {
                result += "?";
                is_correct = false;
                break;
            }
        }
        if(is_correct) {
            result += tmp;
        }
    }
    cout << result;
    return 0;
}