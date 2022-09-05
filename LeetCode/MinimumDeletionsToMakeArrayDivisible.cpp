class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(), nums.end());
        vector<int> temp(nums);
        auto p = unique(nums.begin(), nums.end());
        nums.erase(p, nums.end());
        int index = 0;
        bool status = true;
        sort(numsDivide.begin(), numsDivide.end());
        p = unique(numsDivide.begin(), numsDivide.end());
        numsDivide.erase(p, numsDivide.end());
        for (const auto &p : nums) {
            status = true;
            for (const auto &e : numsDivide) {
                if (e % p != 0) {
                    status = false;
                    break;
                }
            }
            if(status) {
                break;
            }
            ++index;
        }
        if (index != nums.size()) {
            auto it = find(temp.cbegin(), temp.cend(), nums[index]);
            auto otvet = it - temp.cbegin();
            return otvet;
        } else
            return -1;
    }
};

int main() {

  return 0;  
}
