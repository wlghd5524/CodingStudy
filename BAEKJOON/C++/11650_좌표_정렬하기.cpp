#include <iostream>
#include <algorithm>
using namespace std;
class Point {
private:
    int x;
    int y;
public:
    void setX(int inx) {
        x = inx;
    }
    void setY(int iny) {
        y = iny;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
};
bool cmp(Point a, Point b) {
    if (a.getX() == b.getX())
        return a.getY() < b.getY();
    return a.getX() < b.getX();
}
int main() {
    int n, x, y;
    cin >> n;
    Point point[n];
    for (int i = 0; i < n; i++)
        point[i] = Point();
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        point[i].setX(x);
        point[i].setY(y);
    }
    sort(point, point + n, cmp);
    for (int i = 0; i < n; i++)
        cout << point[i].getX() << " " << point[i].getY() << "\n";
}