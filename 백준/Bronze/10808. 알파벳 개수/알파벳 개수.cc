#include <iostream>
using namespace std;
int main()
{
    int alpha[26] = {
        0,
    };
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        alpha[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << alpha[i] << " ";
    }
    return 0;
}