#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, g, tmp, result;
    cin >> n;
    vector<int> num;
    bool done;
    for (int i = 0; i < n; i++) {
        cin >> g;
        vector<int> remainder;
        for (int j = 0; j < g; j++) {
            cin >> tmp;
            num.emplace_back(tmp);
        }
        for (int j = 1;; j++) {
            for (int p = 0; p < num.size(); p++) {
                if (find(remainder.begin(), remainder.end(), num[p] % j) != remainder.end() && remainder.size() != 0) {
                    remainder.clear();
                    done = true;
                    break;
                }
                remainder.emplace_back(num[p] % j);
            }
            if (done == true) {
                done = false;
                continue;
            }
            result = j;
            break;
        }
        cout << result << "\n";
        num.clear();
    }
    return 0;
}