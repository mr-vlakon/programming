class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool> v(k, false);
        int counter = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if ((nums[i] - 1) < k) {
                v[nums[i] - 1] = true;
            }
            int cnt = count(v.cbegin(), v.cend(), true);
            if (cnt == v.size()) {
                return counter;
            }
            ++counter;
        }
        return 0;
    }
};
