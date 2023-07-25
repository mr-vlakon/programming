class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        long long answer = 0;
        long long take = nums[nums.size() - 1];
        for (int i = static_cast<int>(nums.size()) - 2; i >= 0; --i) {
            if (nums[i] <= take) {
                answer = max(answer, take + nums[i]);
                take = take + nums[i];
            } else {
                if (i != 0) {
                    take = nums[i];
                }
                answer = max(static_cast<long long>(nums[i]), answer);
            }
        }
        return answer;
    }
};

int main() {



  return 0;
}
