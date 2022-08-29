class Solution {
public:
    int findMin(vector<int>& nums) {
        auto it = min_element(nums.cbegin(), nums.cend());
        return *it;
    }
};

int main() {
  
  return 0;
}
