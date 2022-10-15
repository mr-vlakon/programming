class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (decltype(nums.size()) i = 0; i != nums.size(); i += 2) {
            sum += min(nums[i], nums[i + 1]);
        }
        return sum;
        
    }
};

int main() {
  
  
  return 0;  
}
