#include <iostream>

using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int p = 0; p < t; p++) {
        int n,count = 0;
        cin >> n;
        for(int i = 5; i <= n; i *= 5) {
            count += n/i;
        }
        cout << count << "\n";
    }
    return 0;
}