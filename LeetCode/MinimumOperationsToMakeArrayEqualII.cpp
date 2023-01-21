class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) {
            return (nums1 == nums2) ? 0 : -1;
        }
        long long cnt1 = 0;
        long long cnt2 = 0;
        for (int i = 0; i != nums1.size(); ++i) {
            if (nums1[i] == nums2[i]) continue;
            if (abs(nums1[i] - nums2[i]) % k != 0) {
                return -1;
            }
            (nums1[i] > nums2[i]) ? (cnt1 += (nums1[i] - nums2[i]) / k) : 
                                    (cnt2 += (nums2[i] - nums1[i]) / k);
        }
        return cnt1 == cnt2 ? cnt1 : -1;
    }
};

int main() {
  
  
  return 0;  
}
