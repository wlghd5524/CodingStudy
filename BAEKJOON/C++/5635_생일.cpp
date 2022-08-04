#include <iostream>
#include <algorithm>
using namespace std;
class Birthday {
private:
    int year;
    int month;
    int date;
    string name;
public:
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDate() { return date; }
    string getName() { return name; }
    void setYear(int x) { year = x; }
    void setMonth(int x) { month = x; }
    void setDate(int x) { date = x; }
    void setName(string x) { name = x; }
};
bool cmp(Birthday a, Birthday b) {
    if(a.getYear() == b.getYear()) {
        if(a.getMonth() == b.getMonth()) {
            return a.getDate() < b.getDate();
        }
        return a.getMonth() < b.getMonth();
    }
    return a.getYear() < b.getYear();
}
int main() {
    int n,date,month,year;
    string name;
    cin >> n;
    Birthday birthday[n];
    for(int i=0;i<n;i++) {
        cin >> name >> date >> month >> year;
        birthday[i].setName(name);
        birthday[i].setDate(date);
        birthday[i].setMonth(month);
        birthday[i].setYear(year);
    }
    sort(birthday,birthday+n,cmp);
    cout << birthday[n-1].getName() << "\n" << birthday[0].getName();
}