class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        if (is_sorted(nums.cbegin(), nums.cend())) return 0;
        int size = nums.size();
        auto minV = min_element(nums.cbegin(), nums.cend());
        auto it = minV;
        auto maxV = max_element(nums.cbegin(), nums.cend());
        int startInd = minV - nums.cbegin();
        int i = 0;
        int prev = *minV;
        while (i != (nums.size() - 1)) {
            prev = *minV;
            ++minV;
            if (minV == nums.cend()) {
                minV = nums.cbegin();
            }
            if (*minV < prev) return -1;
            ++i;
        }
        return nums.cend() - it;
    }
};

int main()
{

  return 0;
}

