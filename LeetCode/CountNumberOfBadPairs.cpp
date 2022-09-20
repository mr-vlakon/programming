class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        if (is_sorted(nums.cbegin(), nums.cend(), [=] (const int &lhs, const int &rhs) {
            return lhs <= rhs;
        })) return 0;
        unordered_map<int, size_t> um;
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            ++um[nums[i] - i];
        }        
        long long good = 0;
        for (const auto &e: um) {
            if (e.second >= 2) {
                int x = 1;
                while (x < e.second) {
                    good += x;
                    ++x;
                }
            }
        }
        long long all = 0;
        long long i = nums.size() - 1;
        while (i > 0) {
            all += i;
            --i;
        }
        long long bad = all - good;
        return bad;
    }
};

int main() {
  
  
  return 0;  
}
