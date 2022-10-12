class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int j = 1; j < n + 1; ++j) {
            int q = -100000;
            for (int i = 0; i < j; ++i) {
                q = max(q, price[i] + dp[j - i - 1]);
            }
            dp[j] = q;
        }
        return dp[n];
    }
};

int main() {
  
  
  return 0;  
}
