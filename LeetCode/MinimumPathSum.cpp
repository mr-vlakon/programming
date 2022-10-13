class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size());
        int n = grid.size();
        for (auto &e: dp) {
            e.resize(grid[0].size(), 0);
        }
        dp[0][0] = grid[0][0];
        for (decltype(grid[0].size()) i = 1; i != grid[0].size(); ++i) {
            dp[0][i] += grid[0][i] + dp[0][i - 1];
        }
        
        for (int j = 1; j < n; ++j) {
            dp[j][0] = grid[j][0] + dp[j - 1][0]; 
            for (int i = 1; i < grid[0].size(); ++i) {
                dp[j][i] = min(grid[j][i] + dp[j][i - 1], grid[j][i] + dp[j - 1][i]);
            }
        }
        return dp[n - 1][grid[0].size() - 1];
    }
};

int main() {
  
  
  
  return 0;  
}
