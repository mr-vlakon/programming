class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> pref;
        vector<int> suffix;
        unordered_set<int> pref_;
        for (int i = 0; i != nums.size(); ++i) {
            pref_.insert(nums[i]);
            pref.push_back(pref_.size());
        }
        unordered_set<int> suffix_;
        for (int i = nums.size() - 1; i >= 0; --i) {
            suffix_.insert(nums[i]);
            suffix.push_back(suffix_.size());
        }
        vector<int> answer;
        int ans = 0;
        for (int i = 0; i != pref.size() - 1; ++i) {
            ans = pref[i] - suffix[pref.size() - 2 - i];
            answer.push_back(ans);
        }
        answer.push_back(pref.back());
        return answer;      
    }
};

int main() {
  
  
  
  return 0;  
}
