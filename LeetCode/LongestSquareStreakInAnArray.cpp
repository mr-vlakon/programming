class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto p = unique(nums.begin(), nums.end());
        nums.erase(p, nums.end());       
        unordered_map<int, int> um;
        for (const auto &e: nums)
            ++um[e];
        int max = 1;
        for (int i = 0; i != nums.size(); ++i) {
            auto it = um.find(static_cast<long long>(nums[i]) * static_cast<long long>(nums[i]));
            if (it != um.cend()) {
                um[it->first] = um[nums[i]] + 1;
                if (um[it->first] > max) {
                    max = um[it->first];
                }
            }
        }
        return (max == 1) ? -1 : max;
    }
};

int main() {
  
  
  
  
  return 0;  
}
