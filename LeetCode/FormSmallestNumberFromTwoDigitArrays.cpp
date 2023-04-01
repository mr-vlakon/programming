class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        auto min1 = *min_element(nums1.cbegin(), nums1.cend());
        auto min2 = *min_element(nums2.cbegin(), nums2.cend());
        int common = -1;
        unordered_set<int> us;
        for (const auto &e: nums1) {
            us.insert(e);
        }
        sort(nums2.begin(), nums2.end());
        for (const auto &e: nums2) {
            if (us.find(e) != us.cend()) {
                common = e;
                break;
            }
        }
        if (min1 == min2) {
            return min1;
        }    
        if (min1 > min2) {
            string tmp = to_string(min2) + to_string(min1);
            string tmp2;
            if (common != -1) {
                if (stoi(tmp) < common) {
                    return stoi(tmp);
                } else {
                    return common;
                }
            }
            return stoi(tmp);
        } else {
            string tmp = to_string(min1) + to_string(min2);
            if (common != -1) {
                if (stoi(tmp) < common) {
                    return stoi(tmp);
                } else {
                    return common;
                }
            }   
            return stoi(tmp);
        }
    }
};

int main() {
  
  
  
  
  return 0;  
}
