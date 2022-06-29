#include <iostream>
#include <vector>
using namespace std;
int main() {
    int k = 0;
    int sum = 0;
    int ins = 0;
    vector<int> arr(k);
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> ins;
        if (ins == 0)
            arr.pop_back();
        else
            arr.push_back(ins);
    }
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];
    cout << sum;
    return 0;
}