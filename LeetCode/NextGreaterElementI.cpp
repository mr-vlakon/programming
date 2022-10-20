class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        for (const auto &e: nums1) {
            auto it = find(nums2.cbegin(), nums2.cend(), e);
            auto search = find_if(it + 1, nums2.cend(), [=](const int &x) {
                return x > e;
            });
            if (search == nums2.cend()) {
                res.push_back(-1);
            } else {
                res.push_back(*search);
            }
        }
        return res;
    }
};

int main() {
  
  
  
  return 0;  
}
