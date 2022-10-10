class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, size_t> um;
        for (decltype(nums.size()) i = 0; i != nums.size() - 1; ++i) {
            if (nums[i] == key) {
                ++um[nums[i + 1]];
            }
        }
        
        int max = 0;
        int val = 0;
        for (const auto &e: um) {
            if (e.second > max) {
                max = e.second;
                val = e.first;
            }
        }
        
        return val;
    }
};

int main() {
  
  
  return 0;  
}
