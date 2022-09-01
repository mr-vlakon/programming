class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [] (const int &lhs, const int &rhs) {
            return lhs > rhs;
        });
        return *(nums.begin() + k - 1);
    }
};

int main() {
  
  return 0;  
}
