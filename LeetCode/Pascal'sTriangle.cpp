class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
        int i = 1;
        for (auto &e : dp) {
            e.resize(i, 1);
            ++i;
        }
        for (int i = 2; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size() - 1; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
     
        return dp;
    }
};

int main() {
  
  
  
  return 0;  
}
