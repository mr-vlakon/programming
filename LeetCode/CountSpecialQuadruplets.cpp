class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int cnt = 0;
        for (decltype(nums.size()) i = 0; i != nums.size() - 3; ++i) {
            for (decltype(nums.size()) j = i + 1; j != nums.size() - 2; ++j) {
                for (decltype(nums.size()) k = j + 1; k != nums.size() - 1; ++k) {
                    for (decltype(nums.size()) d = k + 1; d != nums.size(); ++d) {
                    if (nums[i] + nums[j] + nums[k] == nums[d])
                        ++cnt;
                }
            }
        }
        }
        return cnt; 
    }
};

int main() {
  
  
  return 0;  
}
