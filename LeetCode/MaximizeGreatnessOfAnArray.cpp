class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start = 1;
        int answer = 0;
        for (int i = 0; i != nums.size();) {
            if (start >= nums.size()) {
                break;
            }
            if (nums[start] > nums[i]) {
                ++answer;
                ++start;
                ++i;
            } else {
                ++start;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
