class Solution {
public:
    
    int traverse(vector<int>& nums) {
        vector<int> newNums;
        for (decltype(nums.size()) i = 0; i < nums.size() - 1; ++ i) {
            newNums.push_back((nums[i] + nums[i + 1]) % 10);
        }
        
        if (newNums.size() == 1)
            return newNums[0];
        return traverse(newNums);
                
    }
    
    int triangularSum(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return traverse(nums); 
    }
};

int main() {
  
  
  
  return 0;  
}
