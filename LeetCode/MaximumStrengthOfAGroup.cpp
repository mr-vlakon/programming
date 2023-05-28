class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long answer = 1;
        sort(nums.begin(), nums.end());
        auto it = find_if(nums.cbegin(), nums.cend(), [](const int &x) {
            return x >= 0; 
        });
        int diff = it - nums.cbegin();
        if ((diff % 2) == 1) {
            --diff;
        }
        if (diff < 0) diff = 0;
        int counter = 0;
        for (int i = 0; i != nums.size(); ++i) {
            if (diff != 0 && nums[i] < 0) {
                answer *= nums[i];
                --diff;
                ++counter;
            } else if (nums[i] > 0) {
                answer *= nums[i];
                ++counter; 
            }
        }
        if (counter == 0 && it != nums.cend() && *it == 0) return 0;
        if (counter == 0) {
            return nums[0];
        }
        return answer;
    }
};

int main() {
  
  
  
  return 0;  
}
