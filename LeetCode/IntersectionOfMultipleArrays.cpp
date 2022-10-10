class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, size_t> um;
        size_t size = nums.size();
        for (const auto &e: nums) {
            for (const auto &p: e)
                ++um[p];
        }
        vector<int> result;
        for (const auto &e: um) {
            if (e.second == size)
                result.push_back(e.first);
        }
        sort(result.begin(), result.end());
        return result;
        
    }
};

int main() {
  
  
  return 0;  
}
