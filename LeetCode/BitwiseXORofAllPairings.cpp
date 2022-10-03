class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int size1 = nums1.size();
        int size2 = nums2.size();
        
        int res = 0;
        if (nums2.size() % 2 == 0) {
            res = 0;
            if (nums1.size() % 2 == 0) {
                return 0;
            } else {
                for (const auto &e: nums2) 
                    res ^= e;
            }
        } else {
            res = nums1[0];
            for (decltype(nums1.size()) i = 1; i != nums1.size(); ++i) {
                res ^= nums1[i];
            }
            
            if (nums1.size() % 2 == 0) {
                return res;
            } else {
                for (const auto &e: nums2) 
                    res ^= e;
                return res;
            }

            
            
        }
        
        
        return res;
        
    }
};

int main() {
  
  
  
  return 0;  
}
