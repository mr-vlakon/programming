class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int, size_t> um;
        for (decltype(nums.size()) i = 0; i != nums.size() - 1; ++i) {
            ++um[nums[i] + nums[i + 1]];
        }
        for (const auto &e: um) {
            if (e.second >= 2)
                return true;
        }
        
        return false;
    }
};

int main() {
  
  
  return 0;  
}
