class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        auto it = find_if(nums.begin(), nums.end(), [=](const int &x) {
            return x >= 0; 
        });
        int i = 0;
        auto beg = nums.begin();
        while (beg != it && i != k) {
            (*beg) = -(*beg);
            ++beg;
            ++i;
        }
        int diff = k - i;
        if (diff % 2 == 1) {
            sort(nums.begin(), nums.end());
            it = nums.begin();
            (*it) = -(*it);
        }
        return accumulate(nums.cbegin(), nums.cend(), 0);
    }
};

int main() {
  
  
  
  return 0;  
}
