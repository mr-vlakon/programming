class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int answer = 0;
        int max1 = *max_element(nums1.cbegin(), nums1.cend());
        int max2 = *max_element(nums2.cbegin(), nums2.cend());
        vector<int> maxs1(nums1.size(), 0);
        vector<int> maxs2(nums2.size(), 0);
        maxs1[0] = nums1[0];
        maxs2[0] = nums2[0];
        for (int i = 1; i != maxs1.size(); ++i) {
            maxs1[i] = max(nums1[i], maxs1[i - 1]);
            maxs2[i] = max(nums2[i], maxs2[i - 1]);
        }
        int cnt = 0;
        int maxBack1 = max1;
        int maxBack2 = max2;
        vector<int> dup1 = nums1;
        vector<int> dup2 = nums2;
        for (int i = nums1.size() - 1; i >= 0; --i) {
                if (i == (nums1.size() - 1)) {
                    if (((nums1[i] < maxBack1) || (nums2[i] < maxBack2)) && (nums1[i] != nums2[i])) {
                        ++cnt;
                        swap(nums1[i], nums2[i]);
                        maxBack1 = nums1[i];
                        maxBack2 = nums2[i];
                    }
                }
                else
                {
                    if ((nums1[i] > maxBack1 || nums2[i] > maxBack2) && nums1[i] != nums2[i]) {
                        ++cnt;
                        swap(nums1[i], nums2[i]);
                    } 
                }
        }
        maxBack1 = dup1.back();
        maxBack2 = dup2.back();
        int case2 = INT_MAX;
        for (int i = dup1.size() - 2; i >= 0; --i) {
            if (i == (dup1.size() - 1)) {
                if (((dup1[i] < maxBack1) || (dup2[i] < maxBack2)) && (dup1[i] != dup2[i])) {
                    ++cnt;
                    swap(dup1[i], dup2[i]);
                    maxBack1 = dup1[i];
                    maxBack2 = dup2[i];
                }
            }
            else
            {
                if ((dup1[i] > maxBack1 || dup2[i] > maxBack2) && dup1[i] != dup2[i]) {
                    if (case2 == INT_MAX) {
                        case2 = 1;
                    } else {
                        ++case2;
                    }
                    //++cnt;
                    swap(dup1[i], dup2[i]);
                } 
            }
        }

        
        if (nums1.back() != *max_element(nums1.cbegin(), nums1.cend()) || nums2.back() != *max_element(nums2.cbegin(), nums2.cend())) {
            return -1;
        }
        return min(cnt, case2);
    }
};

int main()
{



  return 0;
}
