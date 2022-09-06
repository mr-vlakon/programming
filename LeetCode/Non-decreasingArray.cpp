class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size() == 1) return true;
        for (decltype(nums.size()) i = 0; i < nums.size(); ++i) {
            vector<int> tmp(nums);
            tmp.erase(tmp.cbegin() + i);
            if (is_sorted(tmp.begin(), tmp.end()))
                return true;
        }
        return false;
    }
};

int main() {
  
  return 0;  
}
