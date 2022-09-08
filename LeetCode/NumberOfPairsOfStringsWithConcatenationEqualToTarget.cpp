class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        vector<string> result;
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            for (decltype(nums.size()) j = 0; j != nums.size(); ++j)
                if (i != j)
                    result.push_back(nums[i] + nums[j]);
        }
        int cnt = 0;
        for (const auto &e: result) {
            if (e == target)
                ++cnt;
        }
        return cnt;
    }
};

int main() {
  
  
  
  return 0;  
}
