class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            int sum1 = accumulate(nums.cbegin() + i + 1, nums.cend(), 0);
            int sum2 = accumulate(nums.cbegin(), nums.cbegin() + i, 0);
            
            if (sum1 == sum2) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
  
  
  return 0;  
}
