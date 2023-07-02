class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int answer = 0;
        int left = -1;
        int right = -1;
        if (left == -1 && (nums[0] % 2 == 0) && (nums[0] <= threshold)) {
            left = 0;
            right = 1;
        }
        for (int i = 1; i != nums.size(); ++i)
        {
            if (left == -1 && (nums[i] % 2 == 0) && (nums[i] <= threshold)) {
                left = i;
                right = i + 1;
            } else if (left != -1 && ((nums[i - 1] % 2) != (nums[i] % 2)) && (nums[i] <= threshold)) {
                right = i + 1;
            } else {
                if (left != -1 && right != -1) {
                    answer = max(answer, right - left);
                }        
                left = -1;
                right = -1;
                if ((nums[i] % 2 == 0) && (nums[i] <= threshold)) {
                    left = i;
                    right = i + 1;
                }
            }
        }
        if (left != -1 && right != -1) {
            answer = max(answer, right - left);
        }
        return answer;
    }
};

int main() {


  
  return 0;
}
