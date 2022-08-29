class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const int &lhs, const int &rhs){
            return lhs > rhs;
        });
        auto p = unique(nums.begin(), nums.end());
        nums.erase(p, nums.end());
        auto it = nums.begin();
        if (nums.begin() + 2 >= nums.end()) {
            return *it;
        } else
            return *(it + 2);
    }
};

int main() {

  return 0; 
}
