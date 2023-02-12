class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long answer = 0;
        for (int i = 0; i <= nums.size() / 2; ++i) {
            if (i != (nums.size() - i - 1) && (i < (nums.size() - i - 1))) {
                string tmp = to_string(nums[i]) + to_string(nums[nums.size() - i - 1]);
                answer += stoll(tmp);
            } else if (i <= (nums.size() - i - 1)) {
                answer += nums[i];
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
