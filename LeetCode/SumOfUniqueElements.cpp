class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0;
        for (const auto &e: nums) {
            if (count(nums.cbegin(), nums.cend(), e) == 1)
                sum += e;
        }
        return sum;
    }
};

int main() {
  
  
  return 0;  
}
