#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int arr[3] = {1,};
    int a = 1, b = 1, c = 1;
    while (arr[0] != 0 || arr[1] != 0 || arr[2] != 0) {
        cin >> arr[0] >> arr[1] >> arr[2];
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
            break;
        sort(arr, arr + 3);
        a = arr[0];
        b = arr[1];
        c = arr[2];
        if (c * c == (a * a) + (b * b) && a != b && b != c)
            cout << "right\n";
        else
            cout << "wrong\n";
    }
}