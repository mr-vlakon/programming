class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int firstPositive = 0;
        int firstMinusPos = -1;
        int lastMinusPos = -1;
        int countM = 0;
        int answer = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == 0) {
                firstMinusPos = -1;
                firstPositive = -1;
                lastMinusPos = -1;
                countM = 0;
            } else if (nums[i] < 0) {
                if (firstMinusPos == -1) {
                    firstMinusPos = i;
                }
                lastMinusPos = i;
                ++countM;
            } else if (nums[i] != 0 && firstPositive == -1) {
                firstPositive = i;
            }
            if ((countM % 2) == 0 && nums[i] != 0) {
                if (firstPositive != -1)
                answer = max(answer, i - firstPositive + 1);
                if (firstMinusPos != -1)
                answer = max(answer, i - firstMinusPos + 1);
            } else if (nums[i] != 0){
                if (lastMinusPos != -1)
                answer = max(answer, i - lastMinusPos);
                if (firstMinusPos != -1)
                answer = max(answer, i - firstMinusPos);
            }
        }
        return answer;
    }
};

int main() {



  return 0;
}
