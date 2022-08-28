class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        map<int, size_t> mp;
        for (const auto &e: nums) {
            ++mp[e];
        }     
        for (const auto &e : mp) {
            if (e.second == 1) {
                return e.first;
            }
        }
        return 0;  
    }
};

int main() {
  
  return 0;  
}
