class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt = 0;
        for (decltype(nums.size()) i = 0; i != nums.size() - 2; ++i) {
            for (decltype(nums.size()) j = i + 1; j != nums.size() - 1; ++j) {
                for (decltype(nums.size()) k = j + 1; k != nums.size(); ++k) {
                    if (nums[j] - nums[i] == diff && nums[k] - nums[j] == diff)
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};

int main() {
  
  
  
  return 0;  
}
