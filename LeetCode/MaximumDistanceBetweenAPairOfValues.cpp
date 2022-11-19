class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int max = 0;
        for (int i = 0; i != nums1.size(); ++i) {
            auto lb = lower_bound(nums2.crbegin(), nums2.crend() - i, nums1[i]);
            if (lb != nums2.crend() - i) {
                if (lb.base() - nums2.cbegin() - 1 - i > max)
                    max = lb.base() - nums2.cbegin() - 1 - i;
            }
        }
        return max;
    }
};

int main() {
  
  return 0;  
}
