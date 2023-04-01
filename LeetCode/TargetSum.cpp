class Solution {
public:
    void generate(const vector<int> &num, int i, int tar) {
        if (i == num.size()) {
            if (tar == target_) {
                ++cnt;
            }
            return;
        }
        tar += num[i];
        generate(num, i + 1, tar);
        tar -= num[i];
        tar -= num[i];
        generate(num, i + 1, tar);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        target_ = target;
        int tmp = 0;
        generate(nums, 0, tmp);
        return cnt;
    }
private:
    int target_ = 0;
    int cnt = 0;
};

int main() {
  
  
  
  return 0;  
}
