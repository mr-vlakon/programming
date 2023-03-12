class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        long long pr = 0;
        int answer = 0;
        for (int i = 0; i != nums.size(); ++i) {
            pr += nums[i];
            if (pr > 0) {
                ++answer;
            } else {
                break;
            }
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
