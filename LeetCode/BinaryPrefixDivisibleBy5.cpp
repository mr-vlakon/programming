class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int tmp = nums[0];
        if (tmp == 0) {
            result.push_back(true);
        } else {
            result.push_back(false);
        }
        for (int i = 1; i != nums.size(); ++i) {
            tmp = (tmp*2 + nums[i]) % 5;
            if ((tmp % 5) == 0) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }
        return result;
    }
};

int main() {
  
  
  
  return 0;  
}
