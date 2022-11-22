class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int max = 0;
        for (decltype(nums.size()) i = 0; i != nums.size() - 1; ++i) {
            int sum = nums[i];
            for (decltype(nums.size()) j = i + 1; j != nums.size(); ++j) {
                if (nums[j] > nums[j - 1]) {
                    sum += nums[j];
                } else {
                    break;
                }
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};

int main() {
  
  
  
  return 0;  
}
