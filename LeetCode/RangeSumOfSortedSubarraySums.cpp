class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> res;
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            int sum = 0;
            for (decltype(nums.size()) j = i; j != nums.size(); ++j) {
                sum += nums[j];
                res.push_back(sum);                
            }
        }
        sort(res.begin(), res.end());
        int result = 0;
        for (decltype(res.size()) i = left - 1; i != right; ++i) {
            result += res[i];
            if (result > 1000000006)
                result %= 1000000007;
        }
        return result;
    }
};

int main() {
  
  
  return 0;  
}
