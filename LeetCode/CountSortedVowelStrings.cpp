class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n, vector<int>(5, 0));
        dp[0][0] = 5;
        dp[0][1] = 4;
        dp[0][2] = 3;
        dp[0][3] = 2;
        dp[0][4] = 1;
        long long sum = 15;
        for (int i = 1; i != dp.size(); ++i) {
            dp[i][0] = sum;
            dp[i][1] = sum - dp[i - 1][0];
            dp[i][2] = dp[i][1] - dp[i - 1][1];
            dp[i][3] = dp[i][2] - dp[i - 1][2];
            dp[i][4] = dp[i][3] - dp[i - 1][3];
            sum = dp[i][0] + dp[i][1] + dp[i][2] + dp[i][3] + dp[i][4];          
        }
        return dp.back()[0];
    }
};

int main() {
  
  
  
  return 0;  
}
