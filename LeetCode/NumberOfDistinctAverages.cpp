class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        unordered_set<double> us;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i <= nums.size() / 2) {
            us.insert(static_cast<double>(nums[i] + nums[nums.size() - i - 1]) / 2.0);
            ++i;
        }
        return us.size();
    }
};

int main() {
  
  
  return 0;  
}
