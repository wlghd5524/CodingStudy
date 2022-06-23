#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    int count = 0;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i<n;i++) {
        cin >> num[i];
        if (num[i]<2)
            break;
        for (int j = 0; j*j <=num[i];j++) {
            if(num[i]%j == 0)
                break;
        }
        count++;
    }
    cout << count;
}