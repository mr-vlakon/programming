class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, size_t> um1;
        for (const auto &e: nums) {
            ++um1[e];
        }
        vector<int> result;
        for (const auto &e: um1) {
            if (e.second == 1) {
                result.push_back(e.first);
            }
        }
        return result;
    }
};

int main() {
  
  return 0;  
}
