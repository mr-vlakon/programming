class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto p = equal_range(nums.cbegin(), nums.cend(), target);
        return p.first - nums.cbegin();
    }
};

int main() {
  
  return 0; 
}
