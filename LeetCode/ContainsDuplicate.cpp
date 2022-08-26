class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (unique(nums.begin(), nums.end()) == nums.cend()) {
            return false;
        }
        return true;
    }
};

int main() {
  
  return 0; 
}
