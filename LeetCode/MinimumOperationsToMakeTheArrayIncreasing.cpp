class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        
        for (decltype(nums.size()) i = 1; i != nums.size(); ++i) {
            int tmp = nums[i];
            nums[i] = max(nums[i - 1] + 1, nums[i]);
            cnt += nums[i] - tmp;
        }
        return cnt; 
    }
};

int main() {
  
  
  return 0;  
}
