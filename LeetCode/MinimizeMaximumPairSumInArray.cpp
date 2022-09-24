class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int max = 0;
        while (i != nums.size() / 2) {
            if (nums[i] + nums[nums.size() - i - 1] > max)
                max = nums[i] + nums[nums.size() - i - 1];
            ++i;
        }
        return max;
    }
};

int main() {
  
  return 0;  
}
