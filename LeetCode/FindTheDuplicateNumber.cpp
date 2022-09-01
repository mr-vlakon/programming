class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, size_t> um;
        for (const auto &e : nums) 
            ++um[e];
        for (const auto &e : um) {
            if (e.second >= 2)
                return e.first;
        }
        return 0;
    }
};

int main() {
  
  
  return 0;  
}
