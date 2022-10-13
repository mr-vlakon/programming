class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size());
        int n = grid.size();
        for (auto &e: dp)
            e.resize(grid.size(), 0);
        for (decltype(grid.size()) i = 0; i != grid.size(); ++i) {
            dp[0][i] = grid[0][i];
        }
        
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                int q = 100000;
                for (int k = 0; k < n; ++k) {
                    if (i != k)
                        q = min(q, grid[j][i] + dp[j - 1][k]);
                }
                dp[j][i] = q;
            }
        }
        return *min_element(dp[n - 1].cbegin(), dp[n - 1].cend());;
        
        
    }
};

int main() {
  
  
  
  return 0;  
}
