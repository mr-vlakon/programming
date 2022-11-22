class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex + 1);
        int i = 1;
        for (auto &e : dp) {
            e.resize(i, 1);
            ++i;
        }
        if (rowIndex <= 1) {
            return dp.back();
        }
        for (int i = 2; i < dp.size(); ++i) {
            for (int j = 1; j < dp[i].size() - 1; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
        return dp.back();     
    }
};

int main() {
  
  
  
  
  return 0;  
}
