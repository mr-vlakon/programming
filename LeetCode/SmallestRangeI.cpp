class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int diff = nums.back() - nums[0];
        diff = diff - 2 * k;
        return diff < 0 ? 0 : diff;
    }
};

int main() {
  
  
  return 0;  
}
