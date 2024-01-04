class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = accumulate(nums1.cbegin(), nums1.cend(), 0ll);
        long long sum2 = accumulate(nums2.cbegin(), nums2.cend(), 0ll);
        int countZeros1 = count(nums1.cbegin(), nums1.cend(), 0);
        int countZeros2 = count(nums2.cbegin(), nums2.cend(), 0);
        long long answer = 0;
        if (countZeros1 == 0) {
            if (sum1 >= sum2) {
                if ((sum1 - sum2) < countZeros2) {
                    return -1;
                }
            }
            if (sum1 < sum2) {
                return -1;
            }
        }
        if (countZeros2 == 0) {
            if (sum2 >= sum1) {
                if ((sum2 - sum1) < countZeros1) {
                    return -1;
                }
            }
            if (sum2 < sum1) {
                return -1;
            }
        }
        if (abs(sum1 - sum2) >= abs(countZeros1 - countZeros2)) {
            if (sum1 >= sum2) {
                return sum1 + countZeros1;
            } else {
                return sum2 + countZeros2;
            }
        } else {
            answer = max(sum1, sum2);
            return max(sum1 + countZeros1, sum2 + countZeros2);
        }
        return -1;
    }
};

int main()
{



  return 0;
}
