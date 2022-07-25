#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, price, count = 0;
    cin >> n >> price;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    while (price > 0) {
        for (int i = v.size() - 1; i >= 0; i--) {
            if (price - v[i] >= 0) {
                price = price - v[i];
                count++;
                break;
            }
        }
    }
    cout << count;
}