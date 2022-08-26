class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (const auto &e: nums2) {
            nums1[m++] = e;   
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main() {
  return 0; 
}
