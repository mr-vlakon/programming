class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int min = 100000000;
        for (int i = 0; i <= nums.size() - k; ++i) {
            if (nums[i + k - 1] - nums[i] < min)
                min = nums[i + k - 1] - nums[i];
        }
        return min;
    }
};

int main() {
  
  
  
  return 0;  
}
