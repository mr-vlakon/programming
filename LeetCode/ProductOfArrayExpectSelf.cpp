class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        int pref = nums[0];
        prefix.push_back(pref);
        for (int i = 1; i != nums.size(); ++i) {
            pref *= nums[i];
            prefix.push_back(pref);
        }
        vector<int> suffix;
        int suf = nums.back();
        suffix.push_back(suf);
        for (int i = nums.size() - 2; i >= 0; --i) {
            suf *= nums[i];
            suffix.push_back(suf);
        } 
        vector<int> result;
        result.push_back(suffix[suffix.size() - 2]);
        for (int i = 1; i != nums.size() - 1; ++i) {
            result.push_back(prefix[i - 1] * suffix[suffix.size() - i - 2]);
        }
        result.push_back(prefix[prefix.size() - 2]);
        return result;
    }
};
