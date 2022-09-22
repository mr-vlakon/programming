class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        int l  = 0, k = nums.size() / 2 + nums.size() % 2;
        for (decltype(result.size()) i = 0; i != nums.size(); ++i) {
            if (i % 2 == 0) {
                result.push_back(nums[l++]);
            } else {
                result.push_back(nums[k++]);
            }
        }        
        return result;
    }
};

int main() {
  
  
  return 0;  
}
