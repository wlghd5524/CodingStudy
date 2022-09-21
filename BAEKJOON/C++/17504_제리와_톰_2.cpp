#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.emplace_back(tmp);
    }
    int a = v[n - 2];
    long long int b = 1;
    long long int c = v[n - 1];
    for (int i = v.size() - 1; i > 0; i--) {
        a = v[i - 1];
        b = a * c + b;
        long long int tmp;
        tmp = b;
        b = c;
        c = tmp;
    }
    cout << c - b << " " << c;
    return 0;
}