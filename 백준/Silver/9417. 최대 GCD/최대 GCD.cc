#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getGcd(int a, int b) // 유클리드 호제법을 이용하여 두 수의 최대공약수 구하는 함수
{
    int mod = a % b;
    while (mod > 0) // mod 연산 값이 0이 될 때까지 나눈 수와 나머지를 mod 연산한다.
    {
        a = b;
        b = mod;
        mod = a % b;
    }
    return b; // mod 연산 값이 0이 될 때 나눈 수가 최대공약수가 된다.
}
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    while (n--)
    {
        string numStr;
        getline(cin, numStr); // 각 테스트마다 입력받는 숫자의 개수를 모르기 때문에 한 줄을 입력 받음
        vector<int> nums;     // 입력받은 숫자들을 int형으로 저장하는 벡터
        string tmp;           // 추출되는 숫자를 임시로 저장
        int length = numStr.size();
        for (int i = 0; i < length; i++) // numStr의 첫번째 문자부터 마지막 문자까지 공백문자를 기준으로 숫자를 추출
        {
            if (numStr[i] != ' ') // 공백문자를 기준으로 숫자를 입력받았기 때문에 공백문자가 아닐 때(숫자일 때)는 tmp에 붙임
            {
                tmp.push_back(numStr[i]);
            }
            if (numStr[i] == ' ' || i == length - 1) // 공백문자이거나 마지막 문자일 때
            {
                nums.push_back(stoi(tmp)); // string형인 tmp를 int형으로 변환하여 nums에 추가
                tmp.clear();
                continue;
            }
        }
        sort(nums.begin(), nums.end(), greater<>()); // 유클리드 호제법을 사용하려면 큰 수에서 작은 수를 mod 연산해야 하기 때문에 내림차순으로 정렬
        int result = 0;                              // 결과값(최대공약수의 최댓값)
        for (int i = 0; i < nums.size(); i++)        // 모든 숫자들을 두 수로 묶어서(브루트포스) 최대공약수를 구하여 최댓값을 구한다.
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int gcd = getGcd(nums[i], nums[j]); // 두 수의 최대공약수 구하기
                if (gcd > result)
                {
                    result = gcd;
                }
            }
        }
        cout << result << "\n";
    }
    return 0;
}
