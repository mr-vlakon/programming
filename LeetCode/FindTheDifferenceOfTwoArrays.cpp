class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> res(2);
        for (const auto &e: nums2) {
            if (find(nums1.cbegin(), nums1.cend(), e) == nums1.cend() &&
                find(res[1].cbegin(), res[1].cend(), e) == res[1].cend())
                res[1].push_back(e);
        }
        
        for (const auto &e: nums1) {
            if (find(nums2.cbegin(), nums2.cend(), e) == nums2.cend() && 
                find(res[0].cbegin(), res[0].cend(), e) == res[0].cend() )
                res[0].push_back(e);
        }        
        return res;
    }
};

int main() {
  
  
  
  return 0;  
}
