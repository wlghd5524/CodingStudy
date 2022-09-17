#include <iostream>
using namespace std;
int main() {
    int n, m, sum = 0;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int p = j + 1; p < n; p++) {
                if (arr[i] + arr[j] + arr[p] <= m && arr[i] + arr[j] + arr[p] > sum)
                    sum = arr[i] + arr[j] + arr[p];
            }
        }
    }
    cout << sum;
    return 0;
}