class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, size_t> mp;
        vector<int> v;
        for (const auto &e: nums) {
            ++mp[e];
        }
        for (const auto &e: mp) {
            size_t size = e.second;
            int cnt = 0;
            while (size > 0 && cnt != 2) {
                v.push_back(e.first);
                --size;
                ++cnt;
            }
        }
        nums = v;        
        return nums.size();        
    }
};

int main() {
  return 0; 
}
