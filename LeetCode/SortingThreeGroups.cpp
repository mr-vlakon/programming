class Solution {
public:
    void generate(const vector<int> &nums, int i, int ans, int prev) {
        if (i == nums.size()) {
            answer = min(ans, answer);
            return;
        }
        if (prev == -1) 
        {
            if (nums[i] == 1) {
                generate(nums, i + 1, ans, 1);
            }
            else {
                generate(nums, i + 1, ans + 1, 1);    
            }
            if (nums[i] == 2) {
                generate(nums, i + 1, ans, 2);
            }
            else {
                generate(nums, i + 1, ans + 1, 2);    
            }
            if (nums[i] == 3) {
                generate(nums, i + 1, ans, 3);
            }
            else {
                generate(nums, i + 1, ans + 1, 3);    
            }
        } else {
            if (prev == 1) {
                if (nums[i] == 1) {
                    generate(nums, i + 1, ans, 1);
                } else if (prev > nums[i]) {
                    generate(nums, i + 1, ans + 1, prev);
                } else {
                    generate(nums, i + 1, ans, nums[i]);
                    generate(nums, i + 1, ans + 1, prev);
                    
                }
            } else if (prev == 2) {
                if (nums[i] == 2) {
                    generate(nums, i + 1, ans, 2);
                } else if (prev > nums[i]) {
                     generate(nums, i + 1, ans + 1, prev);
                } else {
                    generate(nums, i + 1, ans, nums[i]);
                    generate(nums, i + 1, ans + 1, prev);
                
                }
            } else if (prev == 3) {
                if (nums[i] == 3) {
                    generate(nums, i + 1, ans, 3);
                } else if (prev > nums[i]){
                    generate(nums, i + 1, ans + 1, prev);
                } else {
                    generate(nums, i + 1, ans, nums[i]);
                    generate(nums, i + 1, ans + 1, prev);
                }
            }
        }
    }
    
    int minimumOperations(vector<int>& nums) {
        generate(nums, 0, 0, -1);
        return answer;
    }
private:
    int answer = INT_MAX;
};
