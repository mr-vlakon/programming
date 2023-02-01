class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int answer = 1;
        int min = nums[0];
        for (int i = 1; i != nums.size(); ++i) {
            if ((nums[i] - min) > k) {
                min = nums[i];
                ++answer;
            }
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
