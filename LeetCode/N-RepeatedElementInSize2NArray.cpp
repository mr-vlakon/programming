class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        unordered_map<int, size_t> um;
        for (const auto &e: nums)
            ++um[e];
        for (const auto &e: um) {
            if (e.second == n)
                return e.first;
        }
        return 0;
    }
};

int main() {
  
  
  
  return 0;  
}
