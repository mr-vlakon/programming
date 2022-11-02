class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        if (nums.size() == 1) return nums[0];
        
        unordered_map<int, size_t> um;
        unordered_map<int, set<int> > umv;
        
        for (const auto &e: nums) {
            ++um[e % space];
            umv[e % space].insert(e);
        }
        
        int max = 0;
        for (const auto &e: um) {
            if (e.second > max) {
                max = e.second;
            }
        }
        int min = 1000000000;
        for (const auto &e: um) {
            if (e.second == max) {
                auto it = umv.find(e.first);
                if (*(it->second.cbegin()) < min) {
                    min = *(it->second.cbegin());
                }
            }
        }
        return min;
    }
};

int main() {
  
  
  return 0;  
}
