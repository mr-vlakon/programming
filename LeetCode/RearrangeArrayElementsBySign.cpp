class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int index = 0;
        vector<int> minus;
        vector<int> plus;
        for (const auto &e: nums) {
            if (e < 0)
                minus.push_back(e);
            else
                plus.push_back(e);
        }    
        vector<int> result;
        int j = 0;
        int k = 0;
        for(decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            if (i % 2 == 0) {
                result.push_back(plus[k++]);
            } else {
                result.push_back(minus[j++]);
            }
        }
        return result;
    }
};

int main() {
  
  
  return 0;  
}
