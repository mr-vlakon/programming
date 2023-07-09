class Solution {
public:
    int jump(vector<int>& nums) {
        int reachable = 0;
        vector<int> dp(nums.size(), 100000);
        dp[0] = 0;
        for (int i = 0; i != nums.size() - 1; ++i) {
            if (i <= reachable) {
                reachable = max(reachable, nums[i] + i);
                if (reachable < nums.size()) {
                    dp[reachable] = min(dp[reachable], dp[i] + 1);
                } else {
                    dp.back() = min(dp.back(), dp[i] + 1);
                }
            }
        }
        return dp.back();
    }
};

int main() {



  return 0;
}
