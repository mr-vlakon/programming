class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max = *max_element(nums.cbegin(), nums.cend());
        int maxLength = 0;
        int curr = 0;
        for (const auto &e : nums) {
            if (e == max) {
                ++curr;
            } else {
                if (curr > maxLength) {
                    maxLength = curr;
                }
                curr = 0;
            }
        }
        
        if (curr > maxLength) {
            maxLength = curr;
        }
 
        return maxLength;
    }
};

int main() {
  
  
  return 0;  
}
