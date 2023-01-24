class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = nums[1] + max(0, dp[0]);
        multiset<int> ms;
        ms.insert(dp[0]);
        ms.insert(dp[1]);
        for (int i = 2; i < nums.size(); ++i) {
            if (i > k) {
                auto it = ms.find(dp[i - k - 1]);
                if (it != ms.end())
                    ms.erase(it);
            }
            dp[i] = nums[i] + max(0, *(--ms.end()));
            ms.insert(dp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
  
  
  return 0;  
}
