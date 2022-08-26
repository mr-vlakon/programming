class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for (const auto &e : nums)  {
                if (count(nums.cbegin(), nums.cend(), e) == 1) {
                    return e;
                }    
        }
        return 0;
    
    }
};

int main() {
  
  return 0; 
}
