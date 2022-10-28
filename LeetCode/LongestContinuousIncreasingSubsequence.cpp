class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> v(1, 1);
        for (decltype(nums.size()) i = 0; i < nums.size() - 1; ++i) {
            int prev = nums[i];
            int cnt = 1;
            for (decltype(nums.size()) j = i + 1; j < nums.size(); ++j) {
                if (nums[j] > prev) {
                    ++cnt;
                    prev = nums[j];
                } else {
                    break;
                }
            }
            v.push_back(cnt);
        }
        
        return *max_element(v.cbegin(), v.cend());
    }
};

int main() {
  
  
  return 0;  
}
