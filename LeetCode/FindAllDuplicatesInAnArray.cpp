class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, size_t> um;
        for (const auto &e: nums) {
            ++um[e];
        }
        vector<int> result;
        for (const auto &e: um) {
            if (e.second == 2) {
                result.push_back(e.first);
            }
        }
        return result;
    }
};

int main() {
  
  return 0;  
}
