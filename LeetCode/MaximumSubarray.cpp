class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int answer = -100000;
        for (const auto &e: nums) {
            currSum += e;
            if (currSum > answer) {
                answer = currSum;
            }
            currSum = (currSum < 0) ? 0 : currSum;
        }
        return answer;
    }
};

int main() {
  
  return 0;  
}
