class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int min = 10000000;
        for (int i = 0; i != nums.size(); ++i) {
            if (nums[i] == target && abs(i - start) < min) {
                min = abs(i - start);
            }
        }
        return min;
    }
};
int main() {
  
  
  
  return 0;  
}
