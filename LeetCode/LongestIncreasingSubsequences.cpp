class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int tmp = 0;
        for (int i = 1; i != nums.size(); ++i) {
            tmp = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    tmp = max(tmp, dp[j]);
                }
            }
            dp[i] = tmp + 1;
        }
        return *max_element(dp.cbegin(), dp.cend());
    }
};

int main() {
  
  
  
  
  return 0;  
}
