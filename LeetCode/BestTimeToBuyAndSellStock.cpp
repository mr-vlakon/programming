class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), -1);
        dp[0] = 0;
        int minV = prices[0];
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = max(dp[i - 1], prices[i] - minV);
            minV = min(minV, prices[i]);
        }
        return dp.back();
    }
};

int main() {
  
  
  return 0;  
}
