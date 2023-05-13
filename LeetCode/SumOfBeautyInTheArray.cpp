class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> right(nums.size(), 0);
        right[nums.size() - 1] = nums.back();
        for (int i = nums.size() - 2; i >= 0; --i) {
            right[i] = min(right[i + 1], nums[i]);
        }
        int maxV = nums[0];
        int answer = 0;
        for (int i = 1; i != nums.size() - 1; ++i) {
            if (nums[i] > maxV && nums[i] < right[i + 1]) {
                answer += 2;
            } else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) {
                answer += 1;
            }
            maxV = max(nums[i], maxV);
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
