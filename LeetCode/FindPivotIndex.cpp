class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix{0};
        int pref = 0;
        int sum = accumulate(nums.cbegin(), nums.cend(), 0);
        for (const auto &e: nums) {
            pref += e;
            prefix.push_back(pref);
        }
        
        for (int i = 0; i != nums.size(); ++i) {
            sum -= nums[i];
            if (prefix[i] == sum) {
                return i;
            }
            
        }
        
        return -1;
    }
};

int main() {
  
  
  return 0;  
}
