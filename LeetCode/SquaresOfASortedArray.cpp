class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for_each(nums.begin(), nums.end(),[](int &i) {i *=i;});
        sort(nums.begin(), nums.end());
        return nums;
    }
};

int main() {
  
  return 0;
}
