class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
      int even = 0;
      int odd = 0;
      int answer = 0;
      for (int i = 1; i != nums.size(); ++i) {
        if ((i - 1) % 2 == 0) {
          even += nums[i];
        } else {
          odd += nums[i];
        }
      }
      if (even == odd) ++answer;
      int turn = 0;
      for (int i = 1; i != nums.size(); ++i) {
        if (turn == 0) {
            even -= nums[i];
            even += nums[i - 1];
            turn = 1;
        } else {
            odd -= nums[i];
            odd += nums[i - 1];
            turn = 0;
        }
        if (odd == even) ++answer;
      }
      return answer;
    }
};

int main() {
  
  

  return 0;
}
