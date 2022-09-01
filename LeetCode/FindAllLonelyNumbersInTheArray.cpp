class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, size_t> um;
        for (const auto &e: nums) {
            ++um[e];
        }
        vector<int> result;
        for(const auto &e: um) {
            if(e.second == 1) {
                if((um.find(e.first - 1) == um.cend()) 
                   && (um.find(e.first + 1) == um.cend())) {
                    result.push_back(e.first);
                }
            }
        }
        return result;
    }
};

int main() {
  
  return 0; 
}
