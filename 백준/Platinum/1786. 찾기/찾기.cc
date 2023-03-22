#include <iostream>
#include <vector>
using namespace std;
int result = 0;
vector<int> resultArr;
vector<int> makeTable(string pattern)
{
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j = 0;
    for (int i = 1; i < patternSize; i++)
    {
        while (j > 0 && pattern[i] != pattern[j])
        {
            j = table[j - 1];
        }
        if (pattern[i] == pattern[j])
        {
            j++;
            table[i] = j;
        }
    }
    return table;
}
void kmp(string parent, string pattern)
{
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for (int i = 0; i < parentSize; i++)
    {
        while (j > 0 && parent[i] != pattern[j])
        {
            j = table[j - 1];
        }
        if (parent[i] == pattern[j])
        {
            if (j == patternSize - 1)
            {
                result++;
                resultArr.push_back(i - patternSize + 2);
                j = table[j];
            }
            else
            {
                j++;
            }
        }
    }
}
int main()
{
    string parent, pattern;
    getline(cin,parent);
    getline(cin,pattern);
    vector<int> table = makeTable(pattern);
    kmp(parent, pattern);
    cout << result << "\n";
    for (int i = 0; i < result; i++)
    {
        cout << resultArr[i] << "\n";
    }
}