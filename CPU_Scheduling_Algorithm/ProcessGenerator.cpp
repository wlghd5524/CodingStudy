#include <iostream>
#include <fstream>
#include <random>
using namespace std;
int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> execution(2, 30);
    uniform_int_distribution<int> priority(1, 100);
    ofstream file("RandomProcesses.txt");
    if (file.is_open())
    {
        for (int i = 1; i <= 10000; i++)
        {
            file << i << " " << i - 1 << " " << execution(gen) << " " << priority(gen) << "\n";
        }
    }
    return 0;
}