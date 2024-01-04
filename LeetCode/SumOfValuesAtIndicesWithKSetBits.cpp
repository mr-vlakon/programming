class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int i = 0;
        int answer = 0;
        while (i != nums.size()) {
            int tmp = i;
            int cnt1 = 0;
            while (tmp) {
                cnt1 += tmp % 2;
                tmp /= 2;
            }
            if (cnt1 == k) {
                answer += nums[i];
            }
            ++i;
        }
        return answer;
    }
};
