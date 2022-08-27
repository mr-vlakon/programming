class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto p = equal_range(nums.cbegin(), nums.cend(), target);
        int indx1 = p.first - nums.cbegin();
        int indx2 = p.second - nums.cbegin();
        if (indx1 == indx2)
            return {-1,-1};
        else
            return {indx1, --indx2};
    }
};

int main() {
  
  return 0;
}
