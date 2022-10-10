class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int cnt = 0;
        for (decltype(nums.size()) i = 0; i != nums.size() - 1; ++i) {
            for (decltype(nums.size()) j = i + 1; j != nums.size(); ++j) {
                if (nums[i] == nums[j] && ((i*j) % k == 0) )
                    ++cnt;
            }
        }
        return cnt;
    }
};

int main() {

  
  return 0;  
}
