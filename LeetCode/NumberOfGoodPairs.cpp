class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        for (decltype(nums.size()) i = 0; i != nums.size() - 1; ++i) {
            for (decltype(nums.size()) j = i + 1; j != nums.size(); ++j) {
                if (nums[i] == nums[j])
                    ++cnt;
            }
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}
