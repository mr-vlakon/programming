class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        sort(nums.begin(), nums.end());
        int tmp = 0;
        for (auto &e: nums) {
            if (e < 0) {
                tmp = abs(e / value);
                e += tmp * value;
                if ( e < 0) {
                    e += value;
                }
            }
            e %= value;
        }
        sort(nums.begin(), nums.end());
        int miss = 0;
        unordered_map<int, int> um;
        for (const auto &e: nums) {
            ++um[e];
        }
        int prev = 0;
        for (auto &e: nums) {
            if (um[e] > 1) {
                prev = e;
                e += (um[e] - 1) * value;
                --um[prev];
            }
        }
        sort(nums.begin(), nums.end());
        for (const auto &e: nums) {
            if (e >= 0) {
                if (e == miss) {
                    ++miss;
                }
            }
        }
        return miss;
    }
};

int main() {
  
  
  return 0;  
}
