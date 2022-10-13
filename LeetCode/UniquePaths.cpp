class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
   
        dp[0].assign(n, 1);
                
        for (int j = 1; j < m; ++j) {
            dp[j][0] = dp[j - 1][0];
            for (int i = 1; i < n; ++i) {
                dp[j][i] = dp[j][i - 1] + dp[j - 1][i];
            }
        }
        
        return dp[m - 1][n - 1]; 
    }
};

int main() {
  
  
  
  return 0;  
}
