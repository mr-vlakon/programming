class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int prevF = 0;
        int prevS = nums[0];
        int tmp1 = prevS;
        for (int i = 1; i != nums.size() - 1; ++i) {
            tmp1 = max(prevF + nums[i], tmp1);
            prevF = prevS;
            prevS = tmp1;
        }
        prevF = 0;
        prevS = nums[1];
        int tmp2 = prevS;
        for (int i = 2; i < nums.size(); ++i) {
            tmp2 = max(prevF + nums[i], tmp2);
            prevF = prevS;
            prevS = tmp2;
        }    
        return max(tmp1, tmp2);
    }
};

int main() {

  
  return 0;
}
