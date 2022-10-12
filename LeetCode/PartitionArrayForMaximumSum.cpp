class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size() + 1);
        dp[0] = 0;
        dp[1] = arr[0];
        for (int i = 2; i < arr.size() + 1; ++i) {
            int q = -1000;
            for (int j = 1; j <= k && j <= i; ++j) {
                q = max(q, dp[i - j] + *max_element(arr.cbegin() + i - j, arr.cbegin() + i)*j);
            }
            dp[i] = q;            
        }
        
        return dp[arr.size()];     
    }
};

int main() {
  
  
  return 0;  
}
