#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> words;
    bool is_correct = true;
    while (1)
    {
        string word;
        cin >> word;
        if (word == "#" && words.empty())
        {
            break;
        }
        else if (word == "#")
        {
            if (is_correct)
            {
                cout << "Correct\n";
            }
            else
            {
                cout << "Incorrect\n";
            }
            is_correct = true;
            words.clear();
            continue;
        }
        if (!words.empty())
        {
            if (word.size() != words.back().size())
            {
                is_correct = false;
            }
            int cnt = 0;
            for (int i = 0; i < word.size(); i++)
            {
                if (word[i] != words.back()[i])
                {
                    cnt++;
                }
            }
            if (cnt != 1)
            {
                is_correct = false;
            }
        }
        words.push_back(word);
    }
    return 0;
}