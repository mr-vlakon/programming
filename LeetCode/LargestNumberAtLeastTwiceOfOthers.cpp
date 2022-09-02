class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        auto prev = --max_element(tmp.cbegin(), tmp.cend());
        auto max = max_element(nums.cbegin(), nums.cend());
        if (*max >= *prev * 2) {
            return max - nums.cbegin();
        }
        return -1;
    }
};

int main() {
  
  return 0; 
}
