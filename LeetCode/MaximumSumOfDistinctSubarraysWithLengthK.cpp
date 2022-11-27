class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        auto sum = accumulate(nums.cbegin(), nums.cbegin() + k, 0LL);
        unordered_map<int, int> um;
        for (int i = 0; i != k; ++i) {
            um[nums[i]]++;
        }
        long long max = 0;
        if (um.size() == k) {
            if (sum > max)
                max = sum;
        }
        for (int i = 1; i <= nums.size() - k; ++i) {
            sum -= nums[i - 1];
            sum += nums[i + k - 1];
            --um[nums[i - 1]];
            if (um[nums[i - 1]] == 0) {
                um.erase(nums[i - 1]);
            }
            ++um[nums[i + k - 1]];
            if (um.size() == k) {
                if (sum > max)
                    max = sum;
            }
        }
        return max;
    }
};

int main() {
  
  
  return 0;  
}
