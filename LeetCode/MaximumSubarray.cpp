class Solution {
public:
    int maxSubArraySum(const vector<int> &v) {
       int max_so_far = v[0];
       int curr_max = v[0];
       for (decltype(v.size()) i = 1; i < v.size(); ++i) {
            curr_max = max(v[i], curr_max + v[i]);
            max_so_far = max(max_so_far, curr_max);
       }
       return max_so_far;
    }
    
    int maxSubArray(vector<int>& nums) {
        return maxSubArraySum(nums);    
    }
};

int main() {
  
  return 0;  
}
