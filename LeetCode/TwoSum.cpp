class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            for (decltype(nums.size()) j = i + 1; j != nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    return {static_cast<int>(i), static_cast<int>(j)};
                }
            }
        }
        return {0,0};
    }
};

int main() {

  return 0; 
}
