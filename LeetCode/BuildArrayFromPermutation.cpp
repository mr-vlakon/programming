class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int index = 0;
        for (const auto &e: nums) {
            ans[index] = nums[nums[index]];
            ++index;
        }
        return ans;
    }
};

int main() {
  
  
  return 0;  
}
