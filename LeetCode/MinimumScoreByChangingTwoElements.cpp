class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer = 10000000000;
        answer = min(answer, nums.back() - nums[2]);
        answer = min(answer, nums[nums.size() - 3] - nums[0]);
        answer = min(answer, nums[nums.size() - 2] - nums[1]);      
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
