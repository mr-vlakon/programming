class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long answer = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i != nums.size(); ++i) {
            auto it = lower_bound(nums.cbegin() + i + 1, nums.cend(), lower - nums[i]);
            auto iter = upper_bound(nums.cbegin() + i + 1, nums.cend(), upper - nums[i]);
            if (it != nums.cend()) {
                answer += iter - it;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
