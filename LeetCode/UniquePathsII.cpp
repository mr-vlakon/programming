class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size());
        int n = obstacleGrid.size();
        for (auto &e: dp) {
            e.resize(obstacleGrid[0].size(), 0);
        }
        if (obstacleGrid[0][0] == 0)
            dp[0][0] = 1;
        else
            return 0;
        for (decltype(obstacleGrid[0].size()) i = 1; i != obstacleGrid[0].size(); ++i) {
            if (obstacleGrid[0][i] == 1) {
                dp[0][i] = 0;
                break;
            } else {
                dp[0][i] = 1;
            }
        }
        
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[j][0] == 0)
                dp[j][0] = dp[j - 1][0];
            else
                dp[j][0] = 0;
            for (int i = 1; i < obstacleGrid[0].size(); ++i) {
                if (obstacleGrid[j][i] == 1)
                    dp[j][i] = 0;
                else
                    dp[j][i] = dp[j][i - 1] + dp[j - 1][i];
            }
        }

        return dp[n - 1][obstacleGrid[0].size() - 1];    
    }
};

int main() {
  
  
  
  return 0;  
}
