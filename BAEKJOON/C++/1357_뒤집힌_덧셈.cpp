#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string a, b, result;
    cin >> a >> b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    result = to_string(stoi(a) + stoi(b));
    reverse(result.begin(),result.end());
    cout << stoi(result);
    return 0;
}