#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    int n;
    string ex;
    cin >> n;
    cin >> ex;
    vector<int> num(n);
    stack<double> s;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < ex.size(); i++) {
        if (isalpha(ex[i])) {
            s.push(num[ex[i] - 'A']);
        }
        else {
            double a, b;
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();
            if (ex[i] == '+') {
                s.push(a + b);
            }
            else if (ex[i] == '-') {
                s.push(a - b);
            }
            else if (ex[i] == '*') {
                s.push(a * b);
            }
            else if (ex[i] == '/') {
                s.push(a / b);
            }
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << s.top();
}