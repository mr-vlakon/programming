class Solution {
public:
    int maxSum(vector<int>& nums) {
        int answer = -1;
        for (int i = 0; i != nums.size() - 1; ++i) {
            string str1 = to_string(nums[i]);
            int maxD1 = 0;
            for (const auto &e: str1) {
                maxD1 = max(maxD1, e - '0');
            }
            for (int j = i + 1; j != nums.size(); ++j) {
                string str2 = to_string(nums[j]);
                int maxD2 = 0;
                for (const auto &e: str2) {
                    maxD2 = max(maxD2, e - '0');
                }
                if (maxD1 == maxD2) {
                    answer = max(answer, nums[i] + nums[j]);
                }
            }
        }
        return answer;
    }
};
