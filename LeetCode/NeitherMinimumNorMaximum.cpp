class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        auto maxMin = minmax_element(nums.cbegin(), nums.cend());
        for (const auto &e: nums) {
            if (e != *(maxMin.first) && e != *(maxMin.second)) {
                return e;
            }
        }
        return -1;
    }
};

int main() {
  
  
  
  return 0;  
}
