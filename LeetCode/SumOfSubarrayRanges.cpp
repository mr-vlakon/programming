class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long cnt = 0;
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            int max = nums[i];
            int min = nums[i];
            for (decltype(nums.size()) j = i; j != nums.size(); ++j) {
                max = std::max(nums[j], max);
                min = std::min(nums[j], min);
                cnt += max - min;
            }
        }
        return cnt;
    }
};

int main() {
  
 
  return 0;
}
