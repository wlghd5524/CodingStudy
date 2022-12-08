#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0;i<t;i++) {
        int n;
        cin >> n;
        float g_sum = 0;
        int c_sum = 0;
        for(int j = 0;j<n;j++) {
            int c;
            float g;
            cin >> c >> g;
            c_sum += c;
            g_sum += (g * c);
        }
        cout << fixed;
        cout.precision(1);
        cout << c_sum << " " << g_sum/c_sum << "\n";
    }
    return 0;
}