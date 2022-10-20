class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            if (nums[i] != i) {
                return i;
            }
            
        }
        
        
        return nums.size();
    }
};

int main() {
  
  
  return 0;  
}
