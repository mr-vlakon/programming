class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long sum = accumulate(nums.cbegin(), nums.cend(), 0L);
        int cnt = 0;
        long tmp = 0;
        for (decltype(nums.size()) i = 1; i < nums.size(); ++i) {
                tmp += static_cast<long>(nums[i - 1]);
                if (tmp >= sum - tmp)
                    ++cnt;
        }
        return cnt;
    }
};

int main() {

  return 0;  
}
