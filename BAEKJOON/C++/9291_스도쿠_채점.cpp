#include <iostream>
#include <set>
using namespace std;
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        bool is_correct = true;
        int arr[9][9];
        for (int j = 0; j < 9; j++) {
            set<int> s;
            for (int p = 0; p < 9; p++) {
                cin >> arr[j][p];
                s.insert(arr[j][p]);
            }
            if (s.size() < 9) {
                is_correct = false;
            }
        }
        for (int j = 0; j < 9; j++) {
            set<int> s;
            for (int p = 0; p < 9; p++) {
                s.insert(arr[p][j]);
            }
            if (s.size() < 9) {
                is_correct = false;
            }
        }

        for (int x = 0; x < 7; x += 3) {
            for (int y = 0; y < 7; y += 3) {
                set<int> s;
                for (int j = x; j < x + 3; j++) {
                    for (int p = y; p < y + 3; p++) {
                        s.insert(arr[j][p]);
                    }
                }
                if (s.size() < 9) {
                    is_correct = false;
                }
            }
        }

        cout << "Case " << i + 1 << ": ";
        if (is_correct) {
            cout << "CORRECT\n";
        }
        else {
            cout << "INCORRECT\n";
        }
    }
    return 0;
}