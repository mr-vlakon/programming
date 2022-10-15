class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result;
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            result.insert(result.cbegin() + index[i], nums[i]);   
        }
        
        return result;
    }
};

int main() {
  
  
  return 0;  
}
