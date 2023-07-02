class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int take = -1;
        long long answer = 1;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == 1 && take == -1) {
                take = i;
            } else if (nums[i] == 1) {
                answer *= (i - take);
                answer %= 1000000007;
                take = i;
            }
        }
        if (take == -1) return 0;
        return answer;
    }
};

int main() {

  
  return 0;
}
