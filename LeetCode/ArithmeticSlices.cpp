class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int answer = 0;
        int prev = nums[1] - nums[0];
        int dp = 2;
        for (int i = 2; i != nums.size(); ++i) {
            if ((nums[i] - nums[i - 1]) == prev) {
                if (dp >= 3) {
                    answer += dp - 2;
                }
                dp++;
            } else {
                if (dp >= 3) {
                    answer += dp - 2;
                }
                dp = 2;
                prev = nums[i] - nums[i - 1];
            }
        }  
        if (dp >= 3) {
            answer += dp - 2;
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
