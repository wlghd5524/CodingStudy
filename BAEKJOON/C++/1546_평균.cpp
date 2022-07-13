#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    double max = 0;
    double score[n];
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> score[i];
        if (score[i] > max)
            max = score[i];
    }
    for (int i = 0; i < n; i++) {
        score[i] = score[i] / max * 100;
        sum += score[i];
    }
    cout << sum / n;
    return 0;
}