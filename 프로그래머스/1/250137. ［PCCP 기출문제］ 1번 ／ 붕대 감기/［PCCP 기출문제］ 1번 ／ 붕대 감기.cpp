#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int attackCount = 0;
    int healthCount = 0;
    int currentTime = 1;
    while(1) {
        if(attackCount == attacks.size()) {
            break;
        }
        else if(currentTime == attacks[attackCount][0]) {
            answer -= attacks[attackCount++][1];
            healthCount = 0;
        }
        else {
            healthCount++;
            answer += bandage[1];
            if(healthCount == bandage[0]) {
                answer += bandage[2];
                healthCount = 0;
            }
            if(answer > health) {
                answer = health;
            }
        }
        if(answer <= 0) {
            answer = -1;
            break;
        }
        currentTime++;
    }
    return answer;
}
