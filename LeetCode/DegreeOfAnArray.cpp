class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> um;
        for (const auto &e: nums) {
            ++um[e];
        }
        int max = 0;
        for (const auto &e: um) {
            if (e.second > max) {
                max = e.second;
            }
        }
        vector<int> v;
        for (const auto &e:um) {
            if (e.second == max) {
                v.push_back(e.first);
            }
        }
        int i = 0;
        int min = 10000000;
        while (i != v.size()) {
            auto it1 = find(nums.cbegin(), nums.cend(), v[i]);
            auto it2 = find(nums.rbegin(), nums.rend(), v[i]);
            auto iter = it2.base();
            if (iter - it1 < min) {
                min = iter - it1;
            }
            ++i;
        }
        return min;
    }
};

int main() {
  
  
  
  return 0;  
}
