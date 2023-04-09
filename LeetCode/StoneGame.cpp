class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        bool turn = true;
        int maxM = 0;
        int maxY = 0;
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), 0));       
        for (int i = 1; i != piles.size() - 1; ++i) {
            for (int j = i + 1; j != piles.size(); ++j) {
                if (turn) {
                    dp[i][j] = max(dp[i - 1][j] + piles[i], dp[i][j - 1] + piles[i]);
                    maxM = max(dp[i][j], maxM);
                    turn = false;
                } else {
                    dp[i][j] = min(dp[i - 1][j] + piles[i], dp[i][j - 1] + piles[i]);
                    maxY = max(dp[i][j], maxY);
                    turn = true;
                }
            }
        }
        return maxM >= maxY;
    }
};

int main() {
  
  
  
  return 0l  
}
