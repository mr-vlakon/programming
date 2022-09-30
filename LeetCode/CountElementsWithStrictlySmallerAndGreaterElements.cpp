class Solution {
public:
    int countElements(vector<int>& nums) {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        auto min = *min_element(nums.cbegin(), nums.cend());
        auto max = *max_element(nums.cbegin(), nums.cend());
        if (nums.size() <= 2) return 0;
        for (decltype(nums.size()) i = 1; i != nums.size() - 1; ++i) {
            if (nums[i] > min && nums[i] < max)
                ++cnt;
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
