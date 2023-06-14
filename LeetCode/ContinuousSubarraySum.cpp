class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int pref = 0;
        um[0] = -1;
        int t = 0;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i != nums.size(); ++i) {
            pref += nums[i];
            t = pref;
            t %= k;
            it = um.find(t);
            if (it != um.cend()) {
                if ( (i - (it->second)) >= 2)
                    return true;
            }
            if (it == um.cend()) {
               um[t] = i;
            }
        }
        return false;
    }
};

int main() {
  
  
  return 0;  
}
