#include <iostream>
using namespace std;
int main() {
    int t, h, w, n, count = 0, fl, ho;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> h >> w >> n;
        for (int j = 1; j <= w; j++) {
            for (int p = 1; p <= h; p++) {
                count++;
                if (count == n) {
                    fl = p;
                    ho = j;
                    break;
                }
            }
            if (count == n)
                break;
        }
        if (ho / 10 == 0)
            cout << fl << "0" << ho << "\n";
        else
            cout << fl << ho << "\n";
        count = 0;
    }
}