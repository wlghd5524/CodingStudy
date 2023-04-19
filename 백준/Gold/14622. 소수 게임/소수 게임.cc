#include <iostream>
#include <queue>
#include <set>
#define MAX 5000000
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>> dae_q;
    priority_queue<int,vector<int>,greater<int>> kyu_q;
    set<int> prime_list;
    long long int dae_sum = 0;
    long long int kyu_sum = 0;
    bool isPrime[MAX+1];
	for (int i = 0; i <= MAX; i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i <= MAX; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j <= MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}
    isPrime[0] = false;
    isPrime[1] = false;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int dae, kyu;
        cin >> dae;
        if (!isPrime[dae])
        {
            if (kyu_q.size() < 3)
            {
                kyu_sum += 1000;
            }
            else
            {
                kyu_sum += kyu_q.top();
            }
        }
        else {
            if (prime_list.find(dae) != prime_list.end())
            {
                dae_sum -= 1000;
            }
            else
            {
                prime_list.insert(dae);
                dae_q.push(dae);
                if(dae_q.size() > 3) {
                    dae_q.pop();
                }
            }
        }
        
        cin >> kyu;
        if (!isPrime[kyu])
        {
            if (dae_q.size() < 3)
            {
                dae_sum += 1000;
            }
            else
            {
                dae_sum += dae_q.top();
            }
        }
        else {
            if (prime_list.find(kyu) != prime_list.end())
        {
                kyu_sum -= 1000;
            }
            else
            {
                prime_list.insert(kyu);
                kyu_q.push(kyu);
                if(kyu_q.size() > 3) {
                    kyu_q.pop();
                }
            }
        }
        
    }
    if (kyu_sum < dae_sum)
    {
        cout << "소수의 신 갓대웅";
    }
    else if (kyu_sum > dae_sum)
    {
        cout << "소수 마스터 갓규성";
    }
    else
    {
        cout << "우열을 가릴 수 없음";
    }
}