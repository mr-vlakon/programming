class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        
        vector<int> v;
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(v));
        set_intersection(nums1.begin(), nums1.end(), nums3.begin(), nums3.end(), back_inserter(v));
        set_intersection(nums2.begin(), nums2.end(), nums3.begin(), nums3.end(), back_inserter(v));
        
        unordered_set<int> us(v.cbegin(), v.cend());
        return {us.cbegin(), us.cend()};
    }
};

int main() {
  
  
  return 0;  
}
