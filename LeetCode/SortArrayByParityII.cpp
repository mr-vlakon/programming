class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd, even;
        for(decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            if (nums[i] % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        vector<int> result;
        decltype(nums.size()) k = 0, l = 0;
        for(decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            if (i % 2 == 0) {
                result.push_back(even[k++]);
            } else {
                result.push_back(odd[l++]);
            }
        }
        return result;
    }
};

int main() {
  
  return 0;  
}
