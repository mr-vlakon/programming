class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (decltype(nums.size()) i = 0; i <= nums.size() - 3; ++i) {
            if(nums[i] + nums[i + 1] > nums[i + 2] && nums[i] + nums[i + 2] > nums[i + 1]
            && nums[i + 1] + nums[i + 2] > nums[i])
                ans = nums[i] + nums[i + 1] + nums[i + 2];
        }
        return ans;
    }
};

int main() {
  
  
  return 0;  
}
