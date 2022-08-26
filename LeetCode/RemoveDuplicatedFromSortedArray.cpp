class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto p = unique(nums.begin(), nums.end());
        return p - nums.cbegin();
    }
};

int main() {
  return 0; 
}
