class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int start = 0;
        int end = 0;
        int prev = INT_MIN;
        int prev2 = INT_MIN;
        for (int i = 0; i != nums.size() - 2; ++i) {
            if (prev == nums[i]) continue;
            start = i + 1;
            end = nums.size() - 1;
            prev2 = INT_MIN;
            while (start < end) {
                if ((nums[start] + nums[end]) == -nums[i] && prev2 != nums[start]) {
                    result.push_back({nums[i], nums[start], nums[end]});
                    prev2 = nums[start];
                    ++start;
                    --end;
                } else if ((nums[start] + nums[end]) < -nums[i]) {
                    ++start;
                } else {
                    --end;
                }
            }
            prev = nums[i];
        }
        return result;  
    }
};

int main() {
  
  
  
  return 0;  
}
