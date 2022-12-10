#include <iostream>
#include <string>
using namespace std;
int main()
{
    int count = 0;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        if (str == " ")
        {
            cout << 0;
            return 0;
        }
        if (str[i] == ' ')
        {
            if (i != 0 && i != str.size() - 1)
                count++;
        }
    }
    cout << count + 1;
    return 0;
}