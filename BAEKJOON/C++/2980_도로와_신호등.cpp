#include <iostream>
using namespace std;
class TrafficLight {
public:
    int point;
    int red;
    int green;
};
int main() {
    int n, l, time = 0;
    int distance = 0;
    cin >> n >> l;
    TrafficLight tl[n];
    for (int i = 0; i < n; i++) {
        int d, r, g;
        cin >> d >> r >> g;
        tl[i].point = d;
        tl[i].red = r;
        tl[i].green = g;
    }
    int index = 0;
    while (distance < l) {
        if (distance == tl[index].point) {
            if (time % (tl[index].green + tl[index].red) <= tl[index].red) {
                time += (tl[index].red - (time % (tl[index].green + tl[index].red)));
            }
            index++;
        }
        distance++;
        time++;
    }
    cout << time;
    return 0;
}