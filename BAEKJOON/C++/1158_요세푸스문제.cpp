#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, k, index;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = i + 1;
    index = k - 1;
    cout << "<";
    for (int i = 0; i < n; i++) {
        if (i + 1 != n) {
            cout << arr[index] << ", ";
            arr.erase(arr.begin() + index);
        }
        else
            cout << arr[index];
        index += k - 1;
        while (1) {
            if (index >= arr.size())
                index = index - arr.size();
            else
                break;
        }
    }
    cout << ">";
    return 0;
}