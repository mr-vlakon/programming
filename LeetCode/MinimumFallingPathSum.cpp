class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size());
        int n = matrix.size();
        for (auto &e: dp)
            e.resize(matrix.size(), 0);
        for (decltype(matrix.size()) i = 0; i != matrix.size(); ++i) {
            dp[0][i] = matrix[0][i];
        }
        
        for (int j = 1; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                int q = 100000;
                for (int k = 0; k < n; ++k) {
                    if (i == k || (i == k - 1) || (i == k + 1))
                        q = min(q, matrix[j][i] + dp[j - 1][k]);
                }
                dp[j][i] = q;
            }
        }
        return *min_element(dp[n - 1].cbegin(), dp[n - 1].cend());    
    }
};

int main() {
  
  
  return 0;  
}
