class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, size_t> um;
        int i = 1;
        while (i <= nums.size()) {
            um[i] = 0;
            ++i;
        }
        
        for (const auto &e: nums) {
            ++um[e];
        }
        
        vector<int> res(2);
        for (const auto &e: um) {
            if (e.second == 2) {
                res[0] = e.first;
            }
            if (e.second == 0) {
                res[1] = e.first;
            }
        }
        return res;
    }
};

int main() {
  
  
  
  
  return 0;  
}
