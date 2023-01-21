class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> us;
        for (int i = 0; i != nums2.size(); ++i) {
            us.insert(nums2[i]);
        }
        for (int i = 0; i != nums1.size(); ++i) {
            if (us.find(nums1[i]) != us.cend()) {
                return nums1[i];
            }
        }
        return -1;    
    }
};

int main() {
  
  
  
  return 0;  
}
