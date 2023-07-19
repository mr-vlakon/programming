class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int answer = INT_MIN;
        int firstMinus = -1;
        int countM = 0;
        int tmp = 1;
        int allToFirstMinus = 1;
        int lastMinus = -1;
        int allFromLastMinus = 1;
        for (int i = 0; i != nums.size(); ++i) {
            answer = max(answer, nums[i]);            
            if (nums[i] == 0) {
                tmp = 1;
                allToFirstMinus = 1;
                countM = 0;
                firstMinus = -1;
            } else {
                tmp *= nums[i];
                if (firstMinus == -1) {
                    allToFirstMinus *= nums[i];
                }
                if (lastMinus != -1) {
                    allFromLastMinus *= nums[i];
                }
                if (nums[i] < 0) {
                    ++countM;
                    if (firstMinus == -1) {
                        firstMinus = i;
                    }
                    lastMinus = i;
                    allFromLastMinus = nums[i];
                }
                if ((countM % 2) == 0) {
                    answer = max(answer, tmp);
                } else {
                    if (firstMinus != i) {
                        answer = max(answer, tmp / allToFirstMinus);
                    }
                    if (lastMinus != i) {
                        answer = max(answer, tmp / allFromLastMinus);
                    }
                }
            }
        }
        return answer;
    }
};

int main() {



  return 0;
}
