class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> v(nums.cbegin() + n, nums.cend());
        vector<int> q(nums.cbegin(), nums.cbegin() + n);
        vector<int> result;
        int k = 0, l = 0;
        for (decltype(result.size()) i = 0; i != nums.size(); ++i) {
            if (i % 2 == 0) {
                result.push_back(q[k++]);
            } else
                result.push_back(v[l++]);
        }
        return result;
    }
};

int main() {
  
  
  return 0;  
}
