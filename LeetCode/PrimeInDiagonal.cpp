class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int answer = 0;
        bool status = false;
        for (int i = 0; i != nums.size(); ++i) {
                status = false;
                if (nums[i][i] <= 1) {
                    status = true;
                }
                    
                for (int j = 2; (j) <= sqrt(nums[i][i]); ++j) {
                    if (((nums[i][i] % j) == 0)) {
                        status = true;
                        break;
                    } 
                }
                if (!status) {
                    answer = max(nums[i][i], answer);
                }
                status = false;
                if (nums[i][nums.size() - i - 1] <= 1) {
                    status = true;
                }
                for (int j = 2; (j) <= sqrt(nums[i][nums.size() - i - 1]); ++j) {
                    if (((nums[i][nums.size() - i - 1] % j) == 0)) {
                        status = true;
                        break;
                    } 
                }    
                if (!status) {
                    answer = max(nums[i][nums.size() - i- 1], answer);
                }
        }
        return answer;
    }
};

int main() {
  
  
  
  
  return 0;  
}
