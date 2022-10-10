class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> um;
        int ind = 0;
        for (const auto &e: nums) {
            um[e].push_back(ind);
            ++ind;
        }
        
        for (const auto &e: um) {
            for (decltype(e.second.size()) i = 0; i != e.second.size() - 1; ++i) {
                if (abs(e.second[i] - e.second[i + 1]) <= k)
                    return true;
            }
        
        }
        return false;
    }
};

int main() {
  
  
  return 0;  
}
