class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int max = 0;
        if (nums[0] <= 0) return -1;
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            if (find(nums.cbegin() + i + 1, nums.cend(), -nums[i]) != nums.cend()) {
                return nums[i];
            }
        }
        return -1;
    }
};

int main() {
  
  
  return 0;  
}
