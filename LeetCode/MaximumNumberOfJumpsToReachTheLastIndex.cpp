class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(), 0);
        dp[0] = 0;
        int tmp = 0;
        long long target_ = target;
        for (int i = 1; i != nums.size(); ++i) {
            tmp = 0;
            for (int j = 0; j != i; ++j) {
                if ((target_ + nums[j]) >= nums[i] && (-target_ + nums[j]) <= nums[i] && (dp[j] != 0 || j == 0)) {
                    tmp = max(tmp, dp[j] + 1);
                }
            }
            dp[i] = max(dp[i], tmp);
        }
        return (dp.back() == 0) ? -1 : dp.back();
    }
};

int main() {


  return 0;
}
