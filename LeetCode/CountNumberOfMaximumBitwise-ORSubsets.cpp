class Solution {
public:
    void generate(const vector<int> &num, int i, int currOr) {
        if (i == num.size()) {
            if (currOr == maxOr) {
                ++cnt;
            }
            return;
        }
        int tmp = currOr;
        currOr |= num[i];
        generate(num, i + 1, currOr);
        generate(num, i + 1, tmp);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        maxOr = nums[0];
        for (int i = 1; i != nums.size(); ++i) {
            maxOr |= nums[i];
        }
        generate(nums, 0, 0);
        return cnt;
    }
private:
    int cnt = 0;
    int maxOr = 0;
};

int main() {
  
  
  return 0;  
}
