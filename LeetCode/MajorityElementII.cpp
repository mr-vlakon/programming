class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        size_t size = nums.size() / 3;
        unordered_map<int, size_t> um;
        for (const auto &e: nums) {
            ++um[e];
        }
        vector<int> result;
        for (const auto &e: um) {
            if (e.second > size)
                result.push_back(e.first);
        }
        return result;
        
    }
};

int main() {
  
  return 0;  
}
