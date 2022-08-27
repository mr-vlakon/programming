class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        auto it = merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(v));
        if (v.size() % 2 == 1) {
            return v[v.size() / 2];
        } else {
            return (static_cast<double>(v[v.size() / 2 - 1]) + static_cast<double>(v[v.size() / 2])) / 2.0;
        }
        return 0.0;
    }
};

int main() {
  return 0;  
}
