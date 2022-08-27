class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, size_t> mp;
        for (const auto &e : nums) {
            ++mp[e];
        }
        int max_val = 0;
        int max = 0;
        for (const auto &e: mp) {
            if (e.second > max) {
                max = e.second;
                max_val = e.first;
            }
            
        } 
        return max_val;
    }
};

int main() {
  
  
  return 0;  
}
