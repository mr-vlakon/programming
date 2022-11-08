class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ind = nums.size() / 2;
        int cnt = 0;
        for (int j = 0; j != nums.size(); ++j) {
            cnt += abs(nums[j] - nums[ind]);
        }
        return cnt;
        
    }
};

int main() {
  
  
  return 0;  
}
