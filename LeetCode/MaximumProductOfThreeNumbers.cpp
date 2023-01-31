class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int neg = nums[nums.size() - 1] * nums[0] * nums[1];
        int pos = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[nums.size() - 3];
        return max(neg, pos);
    }
};

int main() {
  
  
  return 0;  
}
