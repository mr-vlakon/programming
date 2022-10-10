class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        int i = 0;
        
        if (nums.size() == 1) {
            if (k == 0) {
                return nums;
            } else {
                return {-1};
            }
        }
        
        if ((2*k + 1) > nums.size()) {
            return vector<int>(nums.size(), -1);
        }

        while (i != k) {
            ans[i] = -1;
            ans[nums.size() - i - 1] = -1;
            ++i;
        }
        long long sum = accumulate(nums.cbegin(), nums.cbegin() + 2*k + 1, 0LL);
        ans[i] = sum / ( 2*k + 1);
        ++i;
        for (; i < nums.size() - k;++i) {
            sum -= nums[i - k - 1];
            sum += nums[i + k];

            int tmp = sum / (2*k + 1);
            ans[i] = tmp;
        }        
        return ans;
    }
};

int main() {
  
  
  return 0;  
}
