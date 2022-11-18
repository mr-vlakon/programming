class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long answer = 0;
        long long cnt = 1;
        for (int i = 1; i != prices.size(); ++i) {
            if (prices[i - 1] - prices[i] == 1) {
                ++cnt;
            } else {
                answer += cnt *(cnt + 1) / 2;
                cnt = 1;
            }
        }
        answer += cnt * (cnt + 1) / 2;
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
