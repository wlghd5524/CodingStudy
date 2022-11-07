#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FUNCTIONS_H

/*
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
*/

string longAdd(string x, string y)
{
    if (x.size() < y.size())
    {
        string tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
    for (int i = y.size(); i < x.size(); i++)
    {
        y = "0" + y;
    }
    for (int i = x.size() - 1; i >= 0; i--)
    {
        int tmp = (x[i] - '0') + (y[i] - '0');
        if (tmp >= 10)
        {
            tmp -= 10;
            if (i == 0)
            {
                x = "1" + x;
                x[i + 1] = tmp + '0';
                break;
            }
            else
            {
                x[i - 1]++;
            }
        }
        x[i] = tmp + '0';
    }
    return x;
}

string longSub(string x, string y)
{
    if (x.size() < y.size())
    {
        string tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
    else if (x.size() == y.size())
    {
        if (x[0] < y[0])
        {
            string tmp;
            tmp = x;
            x = y;
            y = tmp;
        }
    }
    for (int i = y.size(); i < x.size(); i++)
    {
        y = "0" + y;
    }
    for (int i = x.size() - 1; i >= 0; i--)
    {
        int tmp = (x[i] - '0') - (y[i] - '0');
        if (tmp < 0)
        {
            tmp += 10;
            x[i - 1]--;
        }
        x[i] = tmp + '0';
    }
    while (*x.begin() == '0')
    {
        x.erase(0, 1);
    }
    return x;
}

string longMulti(string x, string y)
{
    string sum;
    if (x.size() < y.size())
    {
        string tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
    else if (x.size() == y.size())
    {
        if (x[0] < y[0])
        {
            string tmp;
            tmp = x;
            x = y;
            y = tmp;
        }
    }
    int tmp = 0;
    for (int i = y.size() - 1; i >= 0; i--)
    {
        string result;
        tmp = 0;
        for (int j = x.size() - 1; j >= 0; j--)
        {
            int a = (x[j] - '0') * (y[i] - '0') + tmp;
            tmp = 0;
            if (a >= 10)
            {
                tmp = (a / 10);
                result = to_string((a % 10)) + result;
            }
            else
            {
                result = to_string(a) + result;
            }
            if (j == 0 && tmp != 0)
            {
                result = to_string(tmp) + result;
            }
        }
        for (int p = 0; p < y.size() - 1 - i; p++)
        {
            result.push_back('0');
        }
        sum = longAdd(sum, result);
    }
    return sum;
}

int gcd(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int moduloAdd(int a, int b, int mod)
{
    return ((a % mod) + (b % mod)) % mod;
}
int moduloMulti(int a, int b, int mod)
{
    return ((a % mod) * (b % mod)) % mod;
}
int moduloSub(int a, int b, int mod)
{
    return ((a % mod) - (b % mod) + mod) % mod;
}