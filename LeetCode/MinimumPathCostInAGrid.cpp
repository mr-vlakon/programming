class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 100000) );
        for (int j = 0; j != grid[0].size(); ++j) {
            dp[0][j] = grid[0][j];
        }
        for (int i = 0; i != grid.size() - 1; ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                for (int k = 0; k != moveCost[grid[i][j]].size(); ++k) {
                    dp[i + 1][k] = min(dp[i + 1][k], grid[i + 1][k] + dp[i][j] + moveCost[grid[i][j]][k]);
                }
            }
        }
        int minV = INT_MAX;
        for (const auto &e: dp.back()) {
            minV = min(minV, e);
        }
        return minV;
    }
};
/*
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INT_MAX));
        dp[0] = grid[0];
        for (int i = 0; i != grid.size() - 1; ++i) {
            for (int j = 0; j != grid[0].size(); ++j) {
                for (int k = 0; k != moveCost[grid[i][j]].size(); ++k) {
                    dp[i + 1][k] = min(dp[i + 1][k], grid[i + 1][k] + dp[i][j] + moveCost[grid[i][j]][k]);
                }
            }
        }
        return *min_element(dp.back().cbegin(), dp.back().cend());
    }
};
*/

int main() {
  
  
  
  return 0;  
}
