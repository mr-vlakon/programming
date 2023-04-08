class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        vector<pair<int, int>> dp(values.size(), {0, 0});
        dp[0].first = 0;
        dp[0].second = values[0];
        dp[1].first = values[0] + 0 + values[1] - 1; 
        dp[1].second = max(dp[0].second, values[1] + 1);
        for (int i = 2; i != values.size(); ++i) {
            dp[i].first = max(dp[i - 1].first, values[i] - i + dp[i - 1].second);
            dp[i].second = max(dp[i - 1].second, values[i] + i);
        }
        return dp.back().first;
    }
};

int main() {
  
  
  
  
  return 0;  
}
