class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        
        int cnt = 0;
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            int prev = nums[i];
            for (decltype(nums.size()) j = i; j != nums.size(); ++j) {
                if (gcd(prev, nums[j]) == k) {
                    ++cnt;
                }
                prev = gcd(prev, nums[j]);
            }
        }
        
        return cnt;
        
    }
};

int main() {
  
  
  return 0;  
}
