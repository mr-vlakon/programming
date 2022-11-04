class Solution {
public:

    int findMinFibonacciNumbers(int k) {        
        vector<int> dp(3);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        int i = 3;
        while(true) {
            if (dp[i - 1] + dp[i - 2] > k) break;
            dp.push_back(dp[i - 1] + dp[i - 2]);
            ++i;
        }        
        reverse(dp.begin(), dp.end());
        int result = *dp.cbegin();
        int cnt = 1;
        if (result == k) return 1;
        for (decltype(dp.size()) i = 1; i != dp.size(); ++i) {
            if (result + dp[i] > k) {
                continue;
            } else {
                result += dp[i];
                ++cnt;
            }
            if (result == k) {
                return cnt;
            }
        }
        return cnt;
    }
};

int main() {
  
  
  
  return 0;  
}
