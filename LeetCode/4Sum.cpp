class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int start = 0;
        int end = 0;
        int prev = INT_MIN;
        int prev2 = INT_MIN;
        int prev3 = INT_MAX; 
        long long sum = 0;
        long long tmp = 0;
        long long tmp1 = 0;
        for (int i = 0; i != nums.size() - 3; ++i) {
            if (prev3 == nums[i]) continue;
            prev = INT_MIN;
            tmp1 = nums[i] - target;
            for (int j = i + 1; j != nums.size() - 2; ++j) {
                if (nums[j] == prev) continue;
                start = j + 1;
                end = nums.size() - 1;
                tmp = tmp1 + nums[j];
                prev2 = INT_MIN;
                while (start < end) {
                    sum = tmp + nums[start] + nums[end];
                    if (sum == 0 && prev2 != nums[start]) {
                        result.push_back({nums[i], nums[j], nums[start], nums[end]});
                        prev2 = nums[start];
                        ++start;
                        --end;
                    } else if (sum < 0) {
                        ++start;
                    } else {
                        --end;
                    }
                }
                prev = nums[j];
            }
            prev3 = nums[i];
        }
        return result;  
    }
};

int main() {
  
  
  
  
  return 0;  
}
