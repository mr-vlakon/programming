class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int answer = 0;
        int firstSum = 0;
        int secondSum = 0;
        int tmp = 0;
        for (int i = 0; i != firstLen; ++i) {
            firstSum += nums[i];
        }
        int t = 0;
        int diff = 0;
        int secondSumFirst = 0;
        int tMax = 0;
        for (int i = 1; i <= (static_cast<int>(nums.size()) - firstLen); ++i) {
            t = i + firstLen - 1;
            diff = nums.size() - t;
            if (diff >= secondLen) 
            {
                secondSum = 0;
                for (int j = t; j < t + secondLen; ++j) {
                    secondSum += nums[j];
                }
                answer = max(answer, firstSum + secondSum);
                for (int j = (t + 1); j <= (static_cast<int>(nums.size()) - secondLen); ++j) {
                    secondSum -= nums[j - 1];
                    secondSum += nums[j + secondLen - 1];
                    answer = max(answer, firstSum + secondSum);
                }
            }
            firstSum -= nums[i - 1];
            firstSum += nums[i + firstLen - 1];
            if (i > secondLen) 
            {
                secondSumFirst -= nums[i - secondLen - 1];
                secondSumFirst += nums[i - 1];
                tMax = max(tMax, secondSumFirst);
                answer = max(answer, tMax + firstSum);
            } else if (i == secondLen) {
               for (int j = 0; j != secondLen; ++j) {
                    secondSumFirst += nums[j];
                }
                tMax = max(tMax, secondSumFirst);
                answer = max(answer, tMax + firstSum);
            }
            secondSum = 0;
        }
        return answer;
    }
};
/*
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int answer = 0;
        int firstSum = 0;
        int secondSum = 0;
        int tmp = 0;
        for (int i = 0; i != firstLen; ++i) {
            firstSum += nums[i];
        }
        int t = 0;
        int diff = 0;
        for (int i = 1; i <= (static_cast<int>(nums.size()) - firstLen); ++i) {
            if (i > secondLen) 
            {
                secondSum = 0;
                for (int j = 0; j != secondLen; ++j) {
                    secondSum += nums[j];
                }
                answer = max(answer, firstSum + secondSum);
                for (int j = 1; j < (i - secondLen); ++j) {
                    secondSum -= nums[j - 1];
                    secondSum += nums[j + secondLen - 1];
                    answer = max(answer, firstSum + secondSum);
                }
            }
            t = i + firstLen - 1;
            diff = nums.size() - t;
            if (diff >= secondLen) 
            {
                secondSum = 0;
                for (int j = t; j < t + secondLen; ++j) {
                    secondSum += nums[j];
                }
                answer = max(answer, firstSum + secondSum);
                for (int j = (t + 1); j <= (static_cast<int>(nums.size()) - secondLen); ++j) {
                    secondSum -= nums[j - 1];
                    secondSum += nums[j + secondLen - 1];
                    answer = max(answer, firstSum + secondSum);
                }
            }
            firstSum -= nums[i - 1];
            firstSum += nums[i + firstLen - 1];
            secondSum = 0;
        }
        if ((nums.size() - firstLen) >= secondLen) 
        {
            secondSum = 0;
            for (int i = 0; i != secondLen; ++i) {
                secondSum += nums[i];             
            }
            answer = max(secondSum + firstSum, answer);
            for (int i = 1; i <= (static_cast<int>(nums.size()) - secondLen - firstLen); ++i) {
                secondSum -= nums[i - 1];
                secondSum += nums[i + secondLen - 1];
                answer = max(secondSum + firstSum, answer);
            }
        }
        return answer;
    }
};
*/

int main() {




  return 0;
}
