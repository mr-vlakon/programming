class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size(), {1, 1});
        int tmp = 0;
        int maxV = 1;
        int cnt = 0;
        for (int i = 1; i != nums.size(); ++i) {
            tmp = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    tmp = max(tmp, dp[j].first);
                }
            }
            cnt = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j] && dp[j].first == tmp) {
                    cnt += dp[j].second;
                }
            }
            dp[i].second = max(cnt, dp[i].second);
            dp[i].first = tmp + 1;
            maxV = max(dp[i].first, maxV);
        }
        int answer = 0;
        for (const auto &e: dp) {
            if (e.first == maxV) {
                answer += e.second;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
