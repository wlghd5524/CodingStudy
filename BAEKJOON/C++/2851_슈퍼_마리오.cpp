#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    int sum = 0;
    int result = 0;
    bool on = false;
    for (int i = 0; i < 10; i++) {
        int score;
        cin >> score;
        v.emplace_back(score);
        sum += score;
        if (sum == 100) {
            result = 100;
            on = true;
        }
        else if (sum > 100 && on == false) {
            if (100 - (sum - v[i]) >= sum - 100) {
                result = sum;
                on = true;
            }
            else {
                result = sum - v[i];
                on = true;
            }
        }
    }
    if (result == 0) {
        result = sum;
    }
    cout << result;
}