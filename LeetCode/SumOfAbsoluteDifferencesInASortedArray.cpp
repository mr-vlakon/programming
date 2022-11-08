class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> result;
        
        vector<int> prefix{nums[0]};
        vector<int> suffix{nums[nums.size() - 1]};
        for (int i = 1, j = nums.size() - 2; i < nums.size() && j >= 0; ++i, --j) {
            prefix.push_back(prefix.back() + nums[i]);
            suffix.push_back(suffix.back() + nums[j]);
        } 
        for(int i = 0; i != nums.size(); ++i) {
            int temp = nums[i] * i - (nums[i] * (nums.size() - i - 1));
            temp -= (((i - 1) >= 0) ? prefix[i - 1] : 0);
            temp += (static_cast<int>(nums.size()) - i - 2 >= 0) ? suffix[nums.size() - i - 2] : 0;
            result.push_back(temp);
        }
        
        return result;
    }
    
};

int main() {
  
  
  
  
  return 0;  
}
