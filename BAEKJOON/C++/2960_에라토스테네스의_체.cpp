#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k, count = 0, result = 0;
    bool end = false;
    cin >> n >> k;
    vector<int> v(n - 1);
    for (int i = 2; i <= n; i++) {
        v[i - 2] = i;
    }
    while (1) {
        int tmp = v[0];
        for (int i = 0; i < v.size(); i++) {
            if (v[i] % tmp == 0) {
                result = *(v.begin() + i);
                v.erase(v.begin() + i);
                count++;
                i--;
                if (count == k) {
                    end = true;
                    break;
                }
            }
        }
        if (end) {
            break;
        }
    }
    cout << result;
}