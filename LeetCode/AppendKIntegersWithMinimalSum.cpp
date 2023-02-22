class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long answer = 0;
        int cnt = k;
        int diff = nums[0] - 1;
        if (diff > 0) {
            if (diff <= cnt) {
                cnt -= diff;
                answer += (static_cast<long long>(nums[0] - 1)) * static_cast<long long>(nums[0]) / 2;
            } else {
                answer += (static_cast<long long>(cnt)) * static_cast<long long>(cnt + 1) / 2;
                cnt = 0;
            }
        }
        for (int i = 0; i != nums.size() - 1; ++i) {
            if (cnt > 0) {
                diff = nums[i + 1] - nums[i] - 1;
                if (diff > 0) {
                    int start = nums[i] + 1;
                    if ((diff) <= cnt) {
                        cnt -= diff;
                        answer += static_cast<long long>(nums[i] + nums[i + 1])*static_cast<long long>(nums[i + 1] - nums[i] - 1) / 2;

                    } else {
                        answer += (static_cast<long long>(2*(nums[i])  + 1 + cnt)) * static_cast<long long>(cnt) / 2;
                        cnt = 0;
                    }
                }
            } else {
                break;
            }
        }

        if (cnt > 0) {
            answer += static_cast<long long>(cnt) * static_cast<long long>(2 * nums.back() + 1 + cnt) / 2;
        }
        return answer;
    }
};

int main() {
  
  

  return 0;
}
