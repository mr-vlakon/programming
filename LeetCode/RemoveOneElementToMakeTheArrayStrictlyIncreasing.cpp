class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int index = 0;
        for (const auto &e: nums) {
            vector<int> v(nums);
            v.erase(v.cbegin() + index);
            if (is_sorted(v.begin(), v.end(),[=](const int &lhs, const int &rhs) {
              return lhs <= rhs;  
            })) {
                return true;
            }
            ++index;
        }
        return false;
    }
};

int main() {
  
  
  return 0;  
}
