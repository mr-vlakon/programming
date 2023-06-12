class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int tmp = 0;
        int answer = 0;
        vector<int> um(nums.size() + 1, 0);
        um[0] = 1;
        for (int i = 0; i != nums.size(); ++i) {
            if ((nums[i] % 2) == 1) {
                ++tmp;
            }
            if ((tmp - k) >= 0) {
                answer += um[tmp - k];
            }
            ++um[tmp];
        }
        return answer;
    }
};

int main() {
  
  
  return 0;  
}
