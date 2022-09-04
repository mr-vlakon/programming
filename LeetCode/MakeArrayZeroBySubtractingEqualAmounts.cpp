class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto p = unique(nums.begin(), nums.end());
        nums.erase(p, nums.end());
        auto it = find(nums.cbegin(), nums.cend(), 0);
        return (it == nums.cend()) ? nums.size() : (nums.size() - 1);
    }
};

int main() {
  
  return 0;
}
