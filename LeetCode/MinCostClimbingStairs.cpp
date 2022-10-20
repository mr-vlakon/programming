class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1, 0);
        int i = 0;
        for (const auto &e: cost) {
            dp[i] = e;
            ++i;
        }
        dp[cost.size()] = 0;
        for (int i = dp.size() - 3; i >= 0; --i) {
            dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
        }
        
        return min(dp[0], dp[1]);
    }
};

int main() {
  
  
  
  return 0;  
}
