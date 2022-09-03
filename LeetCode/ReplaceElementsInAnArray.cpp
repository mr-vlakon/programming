class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations)     {
        unordered_map<int, size_t> um;
        int index = 0;
        for (const auto &e: nums)
            um[e] = index++;
        for (auto &e: operations) {
            auto it = um.find(e[0]);
            um.insert({e[1], it->second});
            um.erase(e[0]);            
        }
        for (const auto &e: um) {
            nums[e.second] = e.first;
        }
        return nums;
    }
};

int main() {
  
  return 0;  
}
