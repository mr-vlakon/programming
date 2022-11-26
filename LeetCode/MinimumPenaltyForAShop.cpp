class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> dp(customers.size() + 1);
        auto cnt = count(customers.cbegin(), customers.cend(), 'N');
        dp[customers.size()] = cnt;
        int min = cnt;
        for (int i = customers.size() -1 ; i >= 0; --i) {
            if (customers[i] == 'Y') {
                dp[i] = dp[i + 1] + 1;
            } else {
                dp[i] = dp[i + 1] - 1;
            }
            if (dp[i] < min) {
                min = dp[i];
            }
        }
        int answer = 0;
        for (int i = 0; i != dp.size(); ++i) {
            if (dp[i] == min) {
                answer = i;
                break;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
