class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(result));
        auto p = unique(result.begin(), result.end());
        result.erase(p, result.end());
        return result;
    }
};

int main() {
  
  return 0;  
}
