class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums.back();
        int b = nums[nums.size() - 2];
        int c = nums[0];
        int d = nums[1];
        return a * b - c * d;
    }
};

int main() {
  
  
  
  return 0;  
}
