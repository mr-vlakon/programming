class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int maxV = 0;
        int answer = -1;
        int i = 0;
        int currCust = 0;
        int tmp = 0;
        int t = 0;
        while (currCust > 0 || i < customers.size()) {
            if (i < customers.size()) {
                currCust += customers[i];
            }
            t = min(4, currCust);
            currCust -= t;
            tmp += t*boardingCost - runningCost;
            if (tmp > maxV) {
                answer = i + 1;
                maxV = tmp;
            }
            ++i;
        }
        return answer;
    }
};
/*
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int maxV = 0;
        int answer = -1;
        int i = 0;
        int currCust = 0;
        int tmp = 0;
        int t = 0;
        while (i < customers.size()) {
            if (i < customers.size()) {
                currCust += customers[i];
            }
            t = min(4, currCust);
            currCust -= t;
            tmp += t*boardingCost - runningCost;
            if (tmp > maxV) {
                answer = i + 1;
                maxV = tmp;
            }
            ++i;
        }
        if (currCust) {
            t = min(4, currCust);
            int x = currCust / t;
            int y = currCust % t;
            int var = y*boardingCost - runningCost;
            if (var < 0) {
                var = 0;
            }
            if ((tmp < 0 && (x*(t*boardingCost - runningCost) + var) > abs(tmp)) || (tmp > 0 && (t*boardingCost - runningCost) > 0)) {
                tmp = currCust / t;
                answer = i;
                answer += tmp;
                tmp = currCust % t;
                if ((tmp*boardingCost - runningCost) > 0) {
                    answer++;
                }
            }
        }
        return answer;
    }
};
*/

int main() {
  
  
  
  
  return 0;  
}
