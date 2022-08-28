class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool status1 = is_sorted(nums.begin(), nums.end(), [](const int &lhs, const int &rhs) {
            return lhs > rhs;
        });
        bool status2 = is_sorted(nums.begin(), nums.end(), [](const int &lhs, const int &rhs) {
            return lhs < rhs;
        });
        return status1 || status2;       
    }
};

int main() {
  
  return 0;  
}
