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
    
    int minSubArraySum(const vector<int> &v) {
       int min_so_far = v[0];
       int curr_min = v[0];

       for (decltype(v.size()) i = 1; i < v.size(); ++i)
       {
            curr_min = min(v[i], curr_min + v[i]);
            min_so_far = min(min_so_far, curr_min);
       }
       return min_so_far;
    }
    
    
    int maxAbsoluteSum(vector<int>& nums) {
        int min = minSubArraySum(nums);
        int max = maxSubArraySum(nums);
        return (max > abs(min)) ? max : abs(min);
    }
};

int main() {
  
  return 0;  
}
