class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        vector<int> dp(stones.size(), 0);
        auto sum = accumulate(stones.cbegin(), stones.cend(), 0);
        dp[stones.size() - 1] = sum;
        for (int i = stones.size() - 1; i > 1; --i) {
            sum -= stones[i];
            dp[i - 1] = max(dp[i], sum - dp[i]);
        }
        return dp[1];
    }
};

int main() {
  
  
  return 0;  
}
