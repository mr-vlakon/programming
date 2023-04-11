class Solution {
public:
    int minDifference(vector<int>& nums) {
        if (nums.size() <= 4) return 0;
        sort(nums.begin(), nums.end());
        int answer = 2147483647;
        answer = min(answer, ((nums[nums.size() - 4]) - nums[0]));
        answer = min(answer, ((nums[nums.size() - 3]) - nums[1]));
        answer = min(answer, ((nums[nums.size() - 2]) - nums[2]));
        answer = min(answer, ((nums[nums.size() - 1]) - nums[3]));
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
