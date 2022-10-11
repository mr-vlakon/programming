class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, size_t> um;
        for (const auto &e: nums)
            ++um[e];
        int cnt = 0;
        int ans = 0;
        for (auto &e: um) {
            if (e.second >= 2) {
                cnt += e.second / 2;
                e.second -= 2 * (e.second / 2);
            }
        }
        
        for (auto &e: um) {
            if (e.second != 0)
                ++ans;
        }

        return {cnt, ans};
    }
};

int main() {
  
  
  return 0;  
}
